#!/bin/bash

# Change to repository root directory
cd "$(dirname "$0")"

python3 scripts/generate_stats.py
