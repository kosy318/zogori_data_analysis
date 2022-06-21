from collections import deque
N = int(input())

for _ in range(N):
    s, t = list(input()), list(input())
    sidx, tidx = len(s)-1, len(t)-1
    while sidx >= 0 and tidx >= 0:
        if s[sidx] == t[tidx]:
            sidx -= 1
            tidx -= 1
        else:
            sidx -= 2

    print("YES" if tidx == -1 else "NO")