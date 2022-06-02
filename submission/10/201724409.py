N, T, k = map(int, input().split())
arr = [[0]*T for _ in range(k)]
cnt = [0 for _ in range(T)]
inp = [list(map(int, input().split())) for _ in range(N)]
inp.sort(key=lambda x:(x[0],-x[1]), reverse=True)
rest = []
minimumgap = 100000

for c, d in inp:
    if cnt[d-1] != k:
        arr[cnt[d-1]][d-1] = c
        cnt[d-1] += 1
    else:
        for i in range(d-1, 0, -1):
            if cnt[i-1] != k:
                arr[cnt[i-1]][i-1] = c
                cnt[i-1] +=1
                break
        else:
            rest.append([c, d])

for c, d in rest:
    for e in range(d-1, -1, -1):
        if arr[-1][e]-c == 0:
            continue
        minimumgap = min(minimumgap, arr[-1][e]-c)

for i in range(k):
    for j in range(T):
        if arr[i][j] != 0:
            minimumgap = min(minimumgap, arr[i][j])

first = sum(map(sum, arr))
second = first-minimumgap
print(first, second)