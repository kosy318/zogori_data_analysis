# input
input_data = input().split()
nums = list(map(int, input_data[0::2]))
operators = input_data[1::2]

# solve: dp
n = len(nums)
dp = [[[0, 0] for _ in range(n)] for _ in range(n)]

for i in range(n):
    dp[i][i] = [nums[i], nums[i]]

for i in range(1, n):
    for j in range(n-i):
        candidates = []
        for k in range(j, j+i):
            front = dp[j][k]
            behind = dp[k+1][j+i]
            operator = operators[k]
            for m in range(2):
                for p in range(2):
                    expression = str(front[m]) + operator + str(behind[p])
                    candidate = eval(expression)
                    candidates.append(candidate)
        candidates.sort()
        dp[j][j+i] = [candidates[0], candidates[-1]]

# print
print(dp[0][n-1][-1])
