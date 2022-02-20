import sys

n, m = list(map(int, sys.stdin.readline().rstrip().split()))
r = [[0 for i in range(m)] for j in range(n)]
g = [[0 for i in range(m)] for j in range(n)]
b = [[0 for i in range(m)] for j in range(n)]
intense = [[0 for i in range(m)] for j in range(n)]
ans = [[' ' for i in range(m)] for j in range(n)]

for i in range(n):
  line = list(map(int, sys.stdin.readline().rstrip().split()))

  for j, val in enumerate(line):
    if j % 3 == 0:
      r[i][j//3] = val
    elif j % 3 == 1:
      g[i][j//3] = val
    else:
      b[i][j//3] = val

for i in range(n):
  for j in range(m):
    intense[i][j] = 2126 * r[i][j] + 7152*g[i][j] + 722*b[i][j]
    if 0<=intense[i][j]<510000:
      ans[i][j] = '#'
    elif 510000<=intense[i][j]<1020000:
      ans[i][j] = 'o'
    elif 1020000<=intense[i][j]<1530000:
      ans[i][j] = '+'
    elif 1530000<=intense[i][j]<2040000:
      ans[i][j] = '-'
    else:
      ans[i][j] = '.'

for i in range(n):
  ans_line = ''
  for tmp in ans[i]:
    ans_line += tmp
  print(ans_line)
