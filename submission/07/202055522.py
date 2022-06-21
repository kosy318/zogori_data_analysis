matrix = []
N = int(input())
for i in range(N):
    job = list(map(int, input().split()))
    matrix.append(job)

matrix.sort(key=lambda x: (x[1]))

P = []
D = []
for i in range(N):
    P.append(matrix[i][2])
    D.append(matrix[i][1] - matrix[i][0] + 1)

for i in range(1, N):
    j = i-1
    while(True):
        if j == -1:
            break
        if matrix[i][0] > matrix[j][1]:
            break
        j -= 1

    if j == -1:
        nOverlap = 0
        findD = 0
    else:
        nOverlap = P[j] - 10
        findD = D[j]

    if P[i-1] == P[i] + nOverlap:
        P[i] = P[i-1]
        D[i] = min(D[i-1], D[i] + findD)
    else:
        P[i] = max(P[i-1], P[i] + nOverlap)
        if P[i] == P[i-1]:
            D[i] = D[i-1]
        else:
            D[i] = D[i] + findD

print(P[N-1], D[N-1])

