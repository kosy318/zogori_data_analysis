import sys
inp = sys.stdin.readline
N,T,k = map(int,inp().split())
tasks = []
for _ in range(N):
    tasks.append(tuple(map(int,inp().split())))
tasks.sort(reverse=True)

M = [[] for j in range(T+1)]
S = set()
max_cost = 0
second_cost = 0

for i in range(N):
    cost, due = tasks[i]
    d = due
    while d > 0:
        if len(M[d]) != k:
            break
        d -= 1
    if d:
        M[d].append(i)
        S.add(i)
        max_cost += cost

if N < T*k:
    min_value = sys.maxsize
    for i in range(1,T+1):
        if len(M[i]) == k:
            min_value = min(min_value,tasks[M[i][-1]][0])
        second_cost = max_cost - min_value
else:
    max_value = -sys.maxsize
    for day in range(1,T+1):
        t = M[day][-1]
        diff = -sys.maxsize
        for j in range(t,N):
            cost, due = tasks[j]
            if due >= day and j not in S:
                if cost < tasks[t][0]:
                    diff = cost - tasks[t][0]
                    break
        max_value = max(max_value,diff,-tasks[t][0])
    second_cost = max_cost+max_value

print(max_cost, second_cost)