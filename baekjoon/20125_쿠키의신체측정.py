import sys
from typing import Dict, Tuple, Union, List

n : int = int(sys.stdin.readline().rstrip())

board = [[' ' for i in range(n)] for j in range(n)]

for i in range(n):
    board[i] = list(sys.stdin.readline().rstrip())

center = {'x': 0 ,'y':0}

dx = (-1,0,1,0)
dy = (0,-1,0,1)

for x in range(1,n-1):
    for y in range(1,n-1):
        is_heart: bool = True
        for dir in range(4):
            nx = x + dx[dir]
            ny = y + dy[dir]

            if nx >= 0 and ny >= 0 and \
                nx < n and ny < n and board[nx][ny]=='_':
                is_heart = False

        if is_heart:
            center['x'] = x
            center['y'] = y

print(center['x'] + 1 ,center['y'] + 1)

l_arm : int = 0
r_arm : int = 0
waist : int = 0
l_leg : int = 0
r_leg : int = 0

for i in reversed(range(center['y'])):
    if board[center['x']][i] == '*':
        l_arm += 1

for i in range(center['y']+1, n):
    if board[center['x']][i] == '*':
        r_arm += 1

for i in range(center['x']+1,n):
    if board[i][center['y']] == '*':
        waist += 1

for i in range(center['x'] + waist+1,n):
    if board[i][center['y'] - 1] == '*':
        l_leg += 1

for i in range(center['x'] + waist + 1, n):
    if board[i][center['y'] + 1] == '*':
        r_leg += 1

print(l_arm, r_arm, waist, l_leg, r_leg)
