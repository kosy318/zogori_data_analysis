a = input().split()
num = []
op = []
for i in range(len(a)):
    if len(a[i]) == 1:
        tmp = ord(a[i]) - 48
        if 0 <= tmp <= 9:
            num.append(tmp)
        else:
            op.append(a[i])
    else:
        num.append(int(a[i]))
min_dp = [[10**9]*len(num) for _ in range(len(num))]
max_dp = [[-10**9]*len(num) for _ in range(len(num))]

for i in range(len(num)):
    max_dp[i][i] = min_dp[i][i] = num[i]

for k in range(1, len(num)):
    for i in range(len(num)-k):
        j  = i+k
        for x in range(i, j):
            max_dp[i][j] = max(max_dp[i][j], eval(str(max_dp[i][x]) + op[x] + str(max_dp[x+1][j])))
            max_dp[i][j] = max(max_dp[i][j], eval(str(min_dp[i][x]) + op[x] + str(max_dp[x + 1][j])))
            max_dp[i][j] = max(max_dp[i][j], eval(str(max_dp[i][x]) + op[x] + str(min_dp[x + 1][j])))
            max_dp[i][j] = max(max_dp[i][j], eval(str(min_dp[i][x]) + op[x] + str(min_dp[x + 1][j])))

            min_dp[i][j] = min(min_dp[i][j], eval(str(max_dp[i][x]) + op[x] + str(max_dp[x + 1][j])))
            min_dp[i][j] = min(min_dp[i][j], eval(str(min_dp[i][x]) + op[x] + str(max_dp[x + 1][j])))
            min_dp[i][j] = min(min_dp[i][j], eval(str(max_dp[i][x]) + op[x] + str(min_dp[x + 1][j])))
            min_dp[i][j] = min(min_dp[i][j], eval(str(min_dp[i][x]) + op[x] + str(min_dp[x + 1][j])))
print(max_dp[0][-1])

