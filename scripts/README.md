# Kattis Solutions Repository Scripts

This folder contains scripts to help manage my Kattis solutions repository. Below is a comprehensive explanation of how to use these scripts.

## Setup

Before using these scripts, make sure to:

1. Install the required Python packages:
   ```
   pip install -r requirements.txt
   ```

2. Make the scripts executable:
   ```
   chmod +x scripts/*.py scripts/*.sh
   ```

3. Set up the command symlinks (if not already done):
   ```
   ./setup.sh
   ```

## Commands

### Add a Solution

```
./add <filename> <problem-id>
```

This command takes a solution file from your workspace and adds it to the repository.

- `<filename>`: The name of your solution file inside the workspace folder
- `<problem-id>`: The Kattis problem identifier (from the URL)

Example:
```
./add solution.py hello
```

This will:
1. Copy `workspace/solution.py` to `problems/hello/solution.py`
2. Fetch problem metadata from Kattis (title, difficulty, statistics)
3. Create or update `problems/hello/README.md`
4. Update the main README.md table with this problem

If you add a solution for a problem that already exists in a different language, it will:
1. Add the new solution file to the problem folder
2. Update the problem README to list both solutions
3. Update the main README to show both languages for that problem

### List Problems

```
./list
```

This command lists all problems in your repository in a formatted table, showing:
- Problem ID
- Title
- Difficulty
- Languages used

### Show Statistics

```
./stats
```

This command shows statistics about your solutions, including:
- Total problems solved
- Solutions by language
- Solutions by difficulty
- Average difficulty
- Most difficult problems solved

### Open Problem in Browser

```
./open <problem-id>
```

This command opens the Kattis problem page in your default web browser.

Example:
```
./open hello
```

## Workflow

A typical workflow looks like:

1. Work on a solution in the `workspace/` folder
2. Test your solution using Kattis
3. Once successful, add it to your repository:
   ```
   ./add your_solution.py problem_id
   ```
4. Commit your changes:
   ```
   git add problems/problem_id README.md
   git commit -m "Add solution for problem_id"
   git push
   ```

## Technical Details

### Problem READMEs

Each problem folder has a README.md with:
- Problem title and link
- Difficulty rating
- Statistics from Kattis
- List of all solution files with their languages
- Last updated timestamp

### File Organization

- Your working files go in the `workspace/` folder (gitignored)
- Solutions are organized in `problems/<problem-id>/` folders
- Scripts are in the `scripts/` folder

### Metadata Fetching

The `add` command fetches problem metadata by:
1. Accessing the problem's statistics page on Kattis
2. Parsing the HTML to extract title, difficulty, and statistics
3. Using this data to create detailed READMEs

## Troubleshooting

If you encounter any issues:

1. Make sure Python dependencies are installed:
   ```
   pip install -r requirements.txt
   ```

2. Check that scripts are executable:
   ```
   chmod +x scripts/*.py scripts/*.sh
   ```

3. Verify that your Kattis problem ID is correct
