#!/usr/bin/env python3

import os
import re
from collections import Counter


def get_problem_stats():
    """Extract statistics about all problems."""
    problems_dir = 'problems'

    if not os.path.exists(problems_dir):
        return []

    problems = []
    for item in os.listdir(problems_dir):
        problem_dir = os.path.join(problems_dir, item)
        if os.path.isdir(problem_dir):
            readme_path = os.path.join(problem_dir, 'README.md')

            if not os.path.exists(readme_path):
                continue

            try:
                with open(readme_path, 'r') as f:
                    content = f.read()

                # Extract title
                title_match = content.split('\n')[0].replace('# ', '')
                title = title_match if title_match else item

                # Extract difficulty
                difficulty = 'Unknown'
                category = 'Unknown'
                difficulty_line = [line for line in content.split(
                    '\n') if 'Difficulty:' in line]
                if difficulty_line:
                    parts = difficulty_line[0].split(
                        ':', 1)[1].strip().split('(', 1)
                    difficulty = parts[0].split("**")[1].strip()
                    if len(parts) > 1:
                        category = parts[1].replace(')', '').strip()

                # Extract languages
                languages = []
                for file in os.listdir(problem_dir):
                    if os.path.isfile(os.path.join(problem_dir, file)) and file != 'README.md':
                        ext = os.path.splitext(file)[1].lower()
                        if ext in ['.py', '.c', '.cpp', '.java', '.js', '.go', '.rb', '.php', '.cs', '.rs', '.kt', '.swift']:
                            lang = {
                                '.py': 'Python',
                                '.c': 'C',
                                '.cpp': 'C++',
                                '.java': 'Java',
                                '.js': 'JavaScript',
                                '.go': 'Go',
                                '.rb': 'Ruby',
                                '.php': 'PHP',
                                '.cs': 'C#',
                                '.rs': 'Rust',
                                '.kt': 'Kotlin',
                                '.swift': 'Swift'
                            }.get(ext, ext[1:].capitalize())
                            languages.append(lang)

                problems.append({
                    'id': item,
                    'title': title,
                    'difficulty_value': float(difficulty) if difficulty != 'Unknown' and difficulty.replace('.', '', 1).isdigit() else None,
                    'difficulty': difficulty,
                    'category': category,
                    'languages': languages
                })
            except Exception as e:
                print(f"Warning: Error processing {item}: {e}")

    return problems


def categorize_difficulty(value):
    if value is None:
        return "Unknown"
    elif value < 2.0:
        return "Very Easy"
    elif value < 3.0:
        return "Easy"
    elif value < 4.0:
        return "Medium-Easy"
    elif value < 5.0:
        return "Medium"
    elif value < 6.0:
        return "Medium-Hard"
    elif value < 7.0:
        return "Hard"
    elif value < 8.0:
        return "Very Hard"
    else:
        return "Extremely Hard"


def main():
    problems = get_problem_stats()

    if not problems:
        print("No problems found.")
        return

    # Count by language
    language_counter = Counter()
    for problem in problems:
        for lang in problem['languages']:
            language_counter[lang] += 1

    # Count by difficulty category
    difficulty_counter = Counter()
    for problem in problems:
        if problem['difficulty_value'] is not None:
            category = categorize_difficulty(problem['difficulty_value'])
            difficulty_counter[category] += 1
        else:
            difficulty_counter['Unknown'] += 1

    # Get official categories if available
    official_categories = Counter()
    for problem in problems:
        if problem['category'] != 'Unknown':
            official_categories[problem['category']] += 1

    # Print statistics
    print("\n=== Kattis Solutions Statistics ===\n")

    print(f"Total problems solved: {len(problems)}")

    # Print language statistics
    print("\nSolutions by Language:")
    for lang, count in sorted(language_counter.items(), key=lambda x: x[1], reverse=True):
        print(f"  {lang}: {count} ({count/len(problems)*100:.1f}%)")

    print("\nSolutions by Difficulty:")
    for category, count in sorted(difficulty_counter.items(), key=lambda x: (
        float('inf') if x[0] == 'Unknown' else
        {
            'Very Easy': 1,
            'Easy': 2,
            'Medium-Easy': 3,
            'Medium': 4,
            'Medium-Hard': 5,
            'Hard': 6,
            'Very Hard': 7,
            'Extremely Hard': 8
        }.get(x[0], 9)
    )):
        print(f"  {category}: {count} ({count/len(problems)*100:.1f}%)")

    # Print official categories if available
    if official_categories:
        print("\nSolutions by Official Category:")
        for category, count in sorted(official_categories.items(), key=lambda x: x[1], reverse=True):
            print(f"  {category}: {count} ({count/len(problems)*100:.1f}%)")

    # Calculate average difficulty
    difficulties = [p['difficulty_value']
                    for p in problems if p['difficulty_value'] is not None]
    if difficulties:
        avg_difficulty = sum(difficulties) / len(difficulties)
        print(f"\nAverage difficulty: {avg_difficulty:.2f}")

    print("\nMost difficult problems solved:")
    top_difficult = sorted([p for p in problems if p['difficulty_value'] is not None],
                           key=lambda x: x['difficulty_value'], reverse=True)[:5]
    for p in top_difficult:
        print(f"  {p['title']} ({p['id']}): {p['difficulty']}")


if __name__ == "__main__":
    main()
