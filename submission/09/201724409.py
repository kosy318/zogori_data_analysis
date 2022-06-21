S = input().strip()
inp = S.split()
ops = list(filter(lambda x: x in {'+', '-', '*'}, inp))

def calc(idx, start, mid, end) :
    maximum, minimum = float('-inf'), float('inf')
    dx = [0, 0, 1, 1]
    dy = [0, 1, 0, 1]
    for k in range(4):
        maximum = max(maximum, eval(str(dp[start][mid][dx[k]])+ops[mid]+str(dp[mid+1][end][dy[k]])))
        minimum = min(minimum, eval(str(dp[start][mid][dx[k]])+ops[mid]+str(dp[mid+1][end][dy[k]])))
    if idx == 0 :
        return maximum
    return minimum


N = len(inp)//2+1
dp = [[[float('-inf'), float('inf')] for _ in range(N)] for __ in range(N)]

for length in range(N):
    for i in range(N-length):
        if length == 0:
            dp[i][i][0], dp[i][i][1] = eval(inp[i*2]), eval(inp[i*2])
            continue

        for j in range(i, i+length):
            dp[i][i+length][0] = max(dp[i][i+length][0], calc(0, i, j, i+length))
            dp[i][i+length][1] = min(dp[i][i+length][1], calc(1, i, j, i+length))

print(dp[0][-1][0])