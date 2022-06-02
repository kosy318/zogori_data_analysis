from collections import deque

N = int(input())
inp = [list(map(int, input().strip().split())) for _ in range(N)]
inp.sort(key = lambda x: x[1])
final_day = inp[-1][1]
inp = deque(inp)
dp = [[0, 0] for _ in range(final_day+1)]

for i in range(1, final_day+2):
    if not inp:
        break

    while inp and i == inp[0][1]:
        b, e, c = inp.popleft()

        if c == dp[e][0]:
            dp[e][1] = min(dp[e][1], e-b+1)

        elif c > dp[e][0]:
            dp[e][0] = c
            dp[e][1] = e-b+1

        if dp[b-1][0]+c-10 == dp[e][0]:
            dp[e][1] = min(dp[e][1], dp[b-1][1] + e-b+1)

        elif dp[b-1][0]+c-10 > dp[e][0]:
            dp[e][0] = dp[b-1][0]+c-10
            dp[e][1] = dp[b-1][1] + e-b+1

    if dp[i-1][0] == dp[i][0]:
        dp[i][1] = min(dp[i][1], dp[i-1][1])

    elif dp[i-1][0] > dp[i][0]:
        dp[i][0] = dp[i-1][0]
        dp[i][1] = dp[i-1][1]

print(dp[-1][0], dp[-1][1])