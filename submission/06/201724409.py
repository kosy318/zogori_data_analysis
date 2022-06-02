S = input().strip()
N = len(S)
dp = [["" for _ in range(N)] for __ in range(N)]
lengthdp = [[0 for _ in range(N)] for __ in range(N)]


for length in range(1, N+1):
    for start in range(N-length+1):
        end = start+length-1
        if length == 1:
            dp[start][end] = S[start]
            lengthdp[start][end] = 1

        else:
            if S[start] == S[end]:
                dp[start][end] = S[start] + dp[start+1][end-1] + S[end]
                lengthdp[start][end] = lengthdp[start+1][end-1] + 2

            else:
                if lengthdp[start][end-1] == lengthdp[start+1][end]:
                    lengthdp[start][end] = lengthdp[start][end-1]
                    dp[start][end] = min(dp[start][end-1], dp[start+1][end])
                else:
                    if lengthdp[start][end-1] > lengthdp[start+1][end]:
                        dp[start][end] = dp[start][end-1]
                        lengthdp[start][end] = lengthdp[start][end-1]
                    else:
                        dp[start][end] = dp[start+1][end]
                        lengthdp[start][end] = lengthdp[start+1][end]

print(dp[0][-1])