import sys

input = sys.stdin.readline()

S = input.rstrip()

dp = [[S[i] if i==j else "" for i in range(len(S))] for j in range(len(S))]

for i in range(len(S)-2,-1,-1):
    dp[i][i+1] = S[i]+S[i+1] if S[i]==S[i+1] else min(S[i],S[i+1])
    for j in range(i+2,len(S)):
        if S[i]==S[j]:
            dp[i][j] = S[i] + dp[i+1][j-1] + S[j]
        elif len(dp[i+1][j])==len(dp[i][j-1]):
            dp[i][j] = min(dp[i+1][j],dp[i][j-1])
        else:
            dp[i][j] = dp[i+1][j] if len(dp[i+1][j])>len(dp[i][j-1]) else dp[i][j-1]
            
print(dp[0][-1])