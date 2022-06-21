MOVING_COST = 10
WHOLE_DATES = 365 * 3

# input
n = int(input())
cleaning_info = []

for _ in range(n):
    b, e, c = map(int, input().split())
    cleaning_info.append([e, c, e-b+1])

cleaning_info.sort(key=lambda x: (x[0], -x[1], x[2]))

# solve: dp(knapsack)
dp = [[0, 0] for i in range(WHOLE_DATES + 1)]

for date in range(1, WHOLE_DATES + 1):
    candidates = [dp[date-1]]
    for i in range(n):
        end, now_profit, now_dates = cleaning_info[i]

        if end == date:
            prev_profit, prev_dates = dp[date - now_dates]
            p = prev_profit + now_profit - MOVING_COST
            d = prev_dates + now_dates
            candidates.append([p, d])

    candidates.sort(key=lambda x: (-x[0], x[1]))
    dp[date] = candidates[0]

# print
P = dp[WHOLE_DATES][0] + 10
D = dp[WHOLE_DATES][1]
print(P, D)
