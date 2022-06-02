S, T = input(), input()

def getLCQS(lcqs, cqs):
    if len(lcqs) == len(cqs): return min(lcqs, cqs)
    return cqs if len(cqs) > len(lcqs) else lcqs

def checkquasi():
    dp = [['' for j in T] for i in S]

    for i in range(len(S)):
        for j in range(len(T)):
            if S[i]==T[j] :
                for y in [i-1, i-2]:
                    for x in [j-1, j-2]:
                        if y>=0 and x>=0 and S[y]==T[x]:
                            dp[i][j] = getLCQS(dp[i][j], dp[y][x])
                dp[i][j] += S[i]
            elif i>0 and j>0 :
                dp[i][j] = getLCQS(dp[i-1][j], dp[i][j-1])
            
    return dp[len(S)-1][len(T)-1]

print(checkquasi())