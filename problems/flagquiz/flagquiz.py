import sys

data = sys.stdin.readlines()

n = int(data[1].rstrip())

arr = [[] for i in range(n)]
for i in range(n):
    arr[i] = data[i + 2].rstrip().split(", ")

ans = [0 for i in range(n)]
for i in range(n):
    for j in range(n):
        temp = 0
        for k in range(len(arr[0])):
            if(arr[i][k] != arr[j][k]):
                temp += 1
        ans[i] = max(temp, ans[i])


mini = min(ans)


for i in range(n):
    if ans[i] == mini:
        print(", ".join(arr[i]))

