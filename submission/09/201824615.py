token = input().split(' ')
optrs, oprds = token[1::2], list(map(int, token[0::2]))
dp = [[(0, 0) for j in oprds] for i in oprds]

def operate(optr, a, b):
    if optr=='+': return a + b
    if optr=='-': return a - b
    if optr=='*': return a * b
    raise ValueError

def getMinMax(l, r, k):
    cases = []
    for t in range(k):
        for n in dp[l][l+t]:
            for m in dp[l+t+1][r]:
                cases.append(operate(optrs[l+t], n, m))

    return min(cases), max(cases)
 
N = len(oprds)
for k in range(N):
    for r in range(k, N):
        if k : dp[r-k][r] = getMinMax(r-k, r, k)
        else : dp[r-k][r] = oprds[r], oprds[r]

print(dp[0][N-1][1])