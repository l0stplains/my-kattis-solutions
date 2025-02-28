#!/usr/bin/env python3

import os
import sys
import shutil
import requests
from bs4 import BeautifulSoup
import re
import datetime
from pathlib import Path


def fetch_problem_metadata(problem_id):
    """Fetch metadata about the problem from Kattis."""
    url = f"https://open.kattis.com/problems/{problem_id}/statistics"

    try:
        response = requests.get(url)
        response.raise_for_status()

        soup = BeautifulSoup(response.text, 'html.parser')

        # Extract title
        title_element = soup.find('h1')
        raw_title = title_element.text.strip() if title_element else "Unknown Problem"
        title = raw_title.replace(" — Problem Statistics", "")

        # Extract difficulty
        difficulty_element = soup.find('span', class_='difficulty_number')
        difficulty = difficulty_element.text.strip() if difficulty_element else "Unknown"

        # Extract difficulty category
        difficulty_label = soup.find(
            'span', class_='info_label', string='Difficulty')
        difficulty_category = difficulty_label.find_next_sibling(
            'span').text.strip() if difficulty_label else "Unknown"

        # Extract statistics
        stats = {}
        table = soup.find('table', class_='table2')
        if table:
            for row in table.find_all('tr'):
                cells = row.find_all('td')
                if len(cells) >= 2:
                    key = cells[0].text.strip()
                    value = cells[1].text.strip()
                    stats[key] = value

        return {
            'title': title,
            'difficulty': difficulty,
            'difficulty_category': difficulty_category,
            'stats': stats,
            'url': f"https://open.kattis.com/problems/{problem_id}"
        }
    except Exception as e:
        print(f"Warning: Could not fetch problem metadata: {e}")
        return {
            'title': problem_id.capitalize(),
            'difficulty': "Unknown",
            'difficulty_category': "Unknown",
            'stats': {},
            'url': f"https://open.kattis.com/problems/{problem_id}"
        }


def determine_language(filename):
    """Determine programming language from file extension."""
    ext = os.path.splitext(filename)[1].lower()
    extensions = {
        '.py': 'Python',
        '.c': 'C',
        '.cpp': 'C++',
        '.cs': 'C#',
        '.java': 'Java',
        '.js': 'JavaScript',
        '.go': 'Go',
        '.rb': 'Ruby',
        '.php': 'PHP',
        '.rs': 'Rust',
        '.kt': 'Kotlin',
        '.swift': 'Swift',
        '.ts': 'TypeScript',
    }
    return extensions.get(ext, 'Unknown')


def create_problem_readme(problem_dir, metadata, filename, language, update_only=False):
    """Create or update a README for the problem directory."""
    readme_path = os.path.join(problem_dir, 'README.md')
    current_time = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')

    # Get existing languages if the README exists
    existing_languages = []
    existing_files = []
    if os.path.exists(readme_path) and update_only:
        with open(readme_path, 'r') as f:
            content = f.readlines()

        for i, line in enumerate(content):
            if "**Language:**" in line and i+1 < len(content) and "**File:**" in content[i+1]:
                lang_line = line.strip()
                file_line = content[i+1].strip()

                # Extract language and filename
                lang = lang_line.split('**Language:**')[1].strip()
                file_match = re.search(r'\[(.*?)\]', file_line)
                if file_match:
                    file = file_match.group(1)

                    if lang != language or file != filename:  # Avoid duplicates
                        existing_languages.append(lang)
                        existing_files.append(file)

    with open(readme_path, 'w') as f:
        f.write(f"# {metadata['title']}\n\n")
        f.write(
            f"**Problem ID:** [{metadata['url'].split('/')[-1]}]({metadata['url']})\n\n")
        f.write(f"**Difficulty:** {metadata['difficulty']
                                   } ({metadata['difficulty_category']})\n\n")

        # Add statistics if available
        if metadata['stats']:
            f.write("## Statistics\n\n")
            for key, value in metadata['stats'].items():
                f.write(f"- **{key}:** {value}\n")
            f.write("\n")
            f.write(f"> *Last updated: {current_time}*\n\n")

        f.write("## Solutions\n\n")

        # Add the new solution
        f.write(f"- **Language:** {language}\n")
        f.write(f"  **File:** [{filename}](./{filename})\n")

        # Add existing solutions
        for i in range(len(existing_languages)):
            f.write(f"- **Language:** {existing_languages[i]}\n")
            f.write(
                f"  **File:** [{existing_files[i]}](./{existing_files[i]})\n")


def update_main_readme(metadata, problem_id, filename):
    """Update the main README.md file with the new solution, maintaining alphabetical order."""
    new_language = determine_language(filename)
    readme_path = 'README.md'

    with open(readme_path, 'r') as f:
        content = f.read()

    # Define the start and end markers
    start_marker = "<!-- SOLUTIONS_TABLE_START -->"
    end_marker = "<!-- SOLUTIONS_TABLE_END -->"

    start_index = content.find(start_marker)
    end_index = content.find(end_marker)

    if start_index == -1 or end_index == -1:
        print("Warning: Could not find table markers in README.md")
        return

    # Extract the part before, inside, and after the table
    before_table = content[:start_index + len(start_marker)]
    table_content = content[start_index +
                            len(start_marker):end_index].strip().split('\n')
    after_table = content[end_index:]

    # Separate header (first two lines) from the content rows
    header = table_content[:2] if len(table_content) >= 2 else table_content
    rows = table_content[2:] if len(table_content) >= 2 else []

    # Check if this problem already exists in the table
    problem_exists = False
    for i, line in enumerate(rows):
        if f"| [{problem_id}]" in line:
            problem_exists = True
            # Update existing problem entry
            parts = line.split('|')
            if len(parts) >= 5:  # Ensure there are enough columns
                current_languages = parts[4].strip()
                if new_language not in current_languages:
                    languages = f"{current_languages}, {
                        new_language}" if current_languages else new_language
                    parts[4] = f" {languages} "
                    rows[i] = '|'.join(parts)
            break

    if not problem_exists:
        # Create a new problem entry
        new_row = (
            f"| [{problem_id}](problems/{problem_id}) "
            f"| {metadata['title']} "
            f"| {metadata['difficulty']} ({metadata['difficulty_category']}) "
            f"| {new_language} |"
        )
        rows.append(new_row)

    # Sort rows alphabetically by problem ID
    def extract_problem_id(row):
        match = re.search(r'\[(.*?)\]', row)
        return match.group(1).lower() if match else ""

    sorted_rows = sorted(rows, key=extract_problem_id)

    # Reconstruct the updated content
    updated_table = "\n".join(header + sorted_rows)
    new_content = before_table + "\n" + updated_table + "\n" + after_table

    # Write updated content back to README
    with open(readme_path, 'w') as f:
        f.write(new_content)


def main():
    if len(sys.argv) < 3:
        print("Usage: python add_solution.py <filename> <problem_id>")
        sys.exit(1)

    filename = sys.argv[1]
    problem_id = sys.argv[2]

    # Get source and destination paths
    source_path = os.path.join('workspace', filename)
    problem_dir = os.path.join('problems', problem_id)

    # Check if problem directory already exists
    updating = os.path.exists(problem_dir)

    # Create problem directory if it doesn't exist
    os.makedirs(problem_dir, exist_ok=True)

    # Fetch problem metadata from Kattis
    print(f"Fetching metadata for problem '{problem_id}'...")
    metadata = fetch_problem_metadata(problem_id)

    # Extract the original file extension
    _, ext = os.path.splitext(filename)
    new_filename = problem_id + ext

    # Copy file from workspace to problem directory with new filename
    destination_path = os.path.join(problem_dir, new_filename)
    shutil.copy2(source_path, destination_path)
    print(f"Copied solution file to {destination_path}")

    # Determine language
    language = determine_language(filename)

    # Create or update problem README
    create_problem_readme(problem_dir, metadata, filename,
                          language, update_only=updating)
    print(f"{'Updated' if updating else 'Created'} README for {problem_id}")

    # Update main README
    update_main_readme(metadata, problem_id, filename)
    print(f"Updated main README with {problem_id}")

    print(f"\nSuccessfully added solution for '{
          metadata['title']}' ({problem_id})!")
    print(f"Don't forget to commit your changes:")
    print(f"  git add problems/{problem_id}")
    print(f"  git add README.md")
    print(
        f"  git commit -m \"Add {'new' if not updating else 'updated'} solution for {problem_id}\"")


if __name__ == "__main__":
    main()
