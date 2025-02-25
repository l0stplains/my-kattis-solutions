#!/bin/bash

# Change to repository root directory
cd "$(dirname "$0")"

if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ $# -lt 2 ]; then
    echo "Usage: ./add <filename> <problem-id>"
    echo "  <filename>   - File in the workspace directory (without workspace/ prefix)"
    echo "  <problem-id> - Kattis problem identifier (from URL)"
    echo ""
    echo "Additional commands:"
    echo "  ./list       - List all solved problems"
    echo "  ./stats      - Show statistics about solved problems"
    echo "  ./open <id>  - Open problem in browser"
    exit 0
fi

filename="$1"
problem_id="$2"

# Check if file exists in workspace
if [ ! -f "workspace/$filename" ]; then
    echo "Error: File 'workspace/$filename' not found!"
    exit 1
fi

# Execute the Python script to handle the addition
python3 scripts/add_solution.py "$filename" "$problem_id"
