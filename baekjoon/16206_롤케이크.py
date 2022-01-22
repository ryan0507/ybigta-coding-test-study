import sys
from typing import List, Optional, Dict

n,m = list(map(int, sys.stdin.readline().rstrip().split()))
cake_lst : List[int]= list(map(int, sys.stdin.readline().rstrip().split()))
ans : int = 0

pq_lst = []

# 3 Cases
# #1: Cake == 10 (No need to cut)
# #2: Cake % 10 == 0 ( Can get MAX values with -1 cut )
# #3: Cake % 10 != 0 ( ... )
for cake in cake_lst:
    if cake == 10:
        pq_lst.append([cake, 0])
    elif cake != 10 and cake % 10 == 0:
        pq_lst.append([cake, 1])
    else:
        pq_lst.append([cake, 2])

pq_lst.sort(key=lambda x:(x[1],x[0]))

# ------ Greedy Step --------
cnt : int = m
i : int = 0
while cnt != 0 and i!=n:
    q: int = pq_lst[i][0] // 10

    if pq_lst[i][1] == 0 :
        ans+=1
        i+=1

    elif pq_lst[i][1] == 1:
        if cnt >= q - 1:
            ans += q
            cnt -= (q-1)
            i += 1
        else:
            ans += cnt
            cnt = 0
            i += 1
            break

    else :
        if cnt >= q:
            ans += q
            cnt -= q
            i += 1
        else:
            ans += cnt
            cnt = 0
            i += 1
            break

print(ans)
