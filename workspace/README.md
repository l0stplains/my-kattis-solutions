# Workspace

This directory serves as a temporary workspace for your Kattis solutions before they are properly organized into the main repository structure.

## How to Use

1. **Solve your problem:** Write your solution code in this workspace directory.
2. **Add the solution to the repository:** Once your solution is working, use the `add.sh` script to add it to the structured repository.

### Adding a Solution

```bash
./add <filename> <problem-id>
```

Where:
- `<filename>` is the name of your solution file in this workspace directory.
- `<problem-id>` is the Kattis problem identifier (from the problem URL).

For example:
```bash
./add helloworld.py hello
```

This will:
1. Copy your solution from `workspace/helloworld.py` to `problems/hello/hello.py`
2. Fetch the problem metadata from Kattis
3. Create/update a README in the problem directory with details about the problem
4. Add the solution to the main README.md

### Additional Commands

The repository includes other helpful scripts:

```bash
./list                 # List all solved problems
./stats                # Show statistics about solved problems
./open <problem-id>    # Open a problem in the browser
```

## Workflow Tips

1. Work on your solutions in this workspace directory
2. Test your solutions locally or using Kattis
3. When your solution is accepted, add it to the repository using the scripts
4. Commit and push your changes to share your solutions

## Notes

- The workspace directory is ignored by Git to prevent committing temporary files
- Only add solutions that have been accepted by Kattis to maintain quality
- Solutions are automatically sorted alphabetically in the main README
- The scripts can only be called from the project root directory
