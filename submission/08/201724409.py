S, T = input().strip(), input().strip()
row, col = len(S), len(T)
dp = [["" for _ in range(col)] for __ in range(row)]

dr = [-1, -1, -2, -2]
dc = [-1, -2, -1, -2]

for r in range(row):
    for c in range(col):
        if S[r] == T[c]:
            dp[r][c] = S[r]
            for i in range(4):
                nr, nc = r + dr[i], c + dc[i]
                if 0 <= nr < row and 0 <= nc < col:
                    dp[r][c] = min(dp[r][c], dp[nr][nc]+S[r], key=lambda x:(-len(x),x))

answer = ""
for d in dp:
    for a in d:
        answer = min(answer, a, key=lambda x:(-len(x),x))
print(answer)