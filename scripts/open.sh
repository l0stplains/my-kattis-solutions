#!/bin/bash

# Change to repository root directory
cd "$(dirname "$0")"

if [ $# -lt 1 ]; then
    echo "Usage: ./open <problem-id>"
    exit 1
fi

problem_id="$1"
url="https://open.kattis.com/problems/$problem_id"

# Try to open URL based on platform
if command -v xdg-open &> /dev/null; then
    xdg-open "$url"  # Linux
elif command -v open &> /dev/null; then
    open "$url"      # macOS
elif command -v start &> /dev/null; then
    start "$url"     # Windows
else
    echo "Could not open browser. Please visit: $url"
fi
