# input
S = input()
T = input()

# dp
s_length, t_length = len(S), len(T)
dp = [[""]*(t_length+1) for _ in range(s_length+1)]

for i in range(1, s_length+1):
    for j in range(1, t_length+1):
        if S[i-1] == T[j-1]:
            if i == 1 and j == 1:
                candidate = [dp[i-1][j-1]]
            elif i == 1:
                candidate = [dp[i-1][j-1], dp[i-1][j-2]]
            elif j == 1:
                candidate = [dp[i-1][j-1], dp[i-2][j-1]]
            else:
                candidate = [dp[i-1][j-1], dp[i-2][j-1], dp[i-1][j-2], dp[i-2][j-2]]

            candidate.sort(key=lambda x: (-len(x), x))
            dp[i][j] = candidate[0] + S[i-1]

# sorting
answer_candidate = []
for i in range(1, s_length+1):
    dp[i].sort(key=lambda x: (-len(x), x))
    answer_candidate.append(dp[i][0])

answer_candidate.sort(key=lambda x: (-len(x), x))

# answer
print(answer_candidate[0])
