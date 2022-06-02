inp = input()

inp = inp.split()

operands = [int(inp[i]) for i in range(0, len(inp), 2)]
operators = [inp[i] for i in range(1, len(inp), 2)]

dp = [[[None, None, None] for j in operands] for i in operands]

for i in range(0, len(operands)):
    if int(operands[i]) < 0:
        dp[i][i] = [operands[i], None, None]
    else:
        dp[i][i] = [None, None, operands[i]]

for i in range(0, len(operands)):
    x = i + 1
    y = 0

    for j in range(0, len(operands) - i - 1):
        for k in range(1, x - y + 1):
            for leftSign in range(0, 3):
                leftOperand = dp[y][y + k - 1][leftSign]

                if leftOperand is None:
                    continue

                for rightSign in range(0, 3):
                    rightOperand = dp[y + k][x][rightSign]

                    if rightOperand is None:
                        continue

                    calRes = eval(str(leftOperand) + str(operators[y + k - 1]) + str(rightOperand))

                    if calRes < 0:
                        if dp[y][x][0] is None:
                            dp[y][x][0] = calRes
                        else:
                            dp[y][x][0] = min(calRes, dp[y][x][0])
                    elif calRes > 0:
                        if dp[y][x][2] is None:
                            dp[y][x][2] = calRes
                        else:
                            dp[y][x][2] = max(calRes, dp[y][x][2])
                    else:
                        dp[y][x][1] = 0

        x += 1
        y += 1

print(dp[0][len(operands) - 1][2])