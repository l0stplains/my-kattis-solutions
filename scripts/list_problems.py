#!/usr/bin/env python3

import os
import json
from tabulate import tabulate


def get_problem_info(problem_dir):
    """Extract information about a problem from its README."""
    readme_path = os.path.join('problems', problem_dir, 'README.md')

    if not os.path.exists(readme_path):
        return {
            'id': problem_dir,
            'title': problem_dir,
            'difficulty': 'Unknown',
            'category': 'Unknown',
            'language': 'Unknown'
        }

    try:
        with open(readme_path, 'r') as f:
            content = f.read()

        # Extract title from the first line (# Title)
        title_match = content.split('\n')[0].replace('# ', '')
        title = title_match if title_match else problem_dir

        # Extract difficulty
        difficulty = 'Unknown'
        category = 'Unknown'
        difficulty_line = [line for line in content.split(
            '\n') if 'Difficulty:' in line]
        if difficulty_line:
            parts = difficulty_line[0].split(':', 1)[1].strip().split('(', 1)
            difficulty = parts[0].strip()
            if len(parts) > 1:
                category = parts[1].replace(')', '').strip()

        # Determine languages
        langs = []
        language_lines = [line for line in content.split(
            '\n') if '**Language:**' in line]
        for line in language_lines:
            lang = line.split(':', 1)[1].strip()
            langs.append(lang)

        language = ', '.join(langs) if langs else 'Unknown'

        return {
            'id': problem_dir,
            'title': title,
            'difficulty': difficulty,
            'category': category,
            'language': language
        }
    except Exception as e:
        print(f"Warning: Error parsing README for {problem_dir}: {e}")
        return {
            'id': problem_dir,
            'title': problem_dir,
            'difficulty': 'Unknown',
            'category': 'Unknown',
            'language': 'Unknown'
        }


def main():
    problems_dir = 'problems'

    if not os.path.exists(problems_dir):
        print("No problems directory found.")
        return

    problems = []
    for item in os.listdir(problems_dir):
        if os.path.isdir(os.path.join(problems_dir, item)):
            problem_info = get_problem_info(item)
            problems.append(problem_info)

    # Sort problems by difficulty, then by ID
    problems.sort(key=lambda x: (
        float(x['difficulty']) if x['difficulty'] != 'Unknown' and x['difficulty'].replace(
            '.', '', 1).isdigit() else float('inf'),
        x['id']
    ))

    # Format as a table
    table_data = [
        [p['id'], p['title'], f"{p['difficulty']
                                 } ({p['category']})", p['language']]
        for p in problems
    ]

    headers = ["ID", "Title", "Difficulty", "Language(s)"]
    print(tabulate(table_data, headers=headers, tablefmt="grid"))
    print(f"\nTotal problems solved: {len(problems)}")


if __name__ == "__main__":
    main()
