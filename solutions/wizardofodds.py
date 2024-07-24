import sys

arr = list(map(int, sys.stdin.readline().split()))

n, k = arr[0], arr[1];

ans = False
if k > 360:
    ans = True
else:
    ans = n <= 2 ** k

if ans:
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")


