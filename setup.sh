#!/bin/bash

# Create symlinks in the root directory for easy access
cd "$(dirname "$0")"

# Make scripts executable
chmod +x scripts/*.py
chmod +x scripts/*.sh

# Create symlinks for main commands
ln -sf scripts/add.sh add
ln -sf scripts/list.sh list
ln -sf scripts/stats.sh stats
ln -sf scripts/open.sh open

echo "Setup complete! You can now use the following commands:"
echo "  ./add <filename> <problem-id>"
echo "  ./list"
echo "  ./stats"
echo "  ./open <problem-id>"
