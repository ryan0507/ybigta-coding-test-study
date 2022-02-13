import sys
from typing import Tuple, List, Union, Dict

n : int = int(sys.stdin.readline().rstrip())
p : List[int] = list(map(int, sys.stdin.readline().rstrip().split()))

ans : int = 0
eps : float = 1e-10
for i in range(n):
    cur_petal : int = 0
    for j in range(i,n):
        cur_petal += p[j]
        avg = cur_petal / (j-i+1)

        find : bool = False
        for k in range(i,j+1):
            if abs(avg - p[k]) < eps:
                find = True

        if find:
            ans += 1

print(ans)
