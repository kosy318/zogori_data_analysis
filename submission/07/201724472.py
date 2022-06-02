import sys

def get_days(u_list, us):
    days = 0
    for k in us:
        days += u_list[k][1] - u_list[k][0] + 1
    return days

def money(u_list, idx):
    money = 0
    if len(idx) == 0:
        return 0
    for k in idx:
        money += u_list[k][2] - 10
    money += 10
    return money

def main():
    N = int(sys.stdin.readline().strip())
    u_list = []
    dp = [[] for _ in range(365*3+2)]

    for _ in range(N):
        u_list.append(list(map(int, sys.stdin.readline().strip().split())))

    u_list.sort(key=lambda x: x[0])
    u_list.sort(key=lambda x: x[1])

    for k in range(2, 365*3+1):
        temp = []
        for t in range(0, len(u_list)):
            j = u_list[t]
            if j[1] == k+1:
                break
            elif j[1] == k:
                temp.append([t, money(u_list, dp[j[0]-1]+[t]), get_days(u_list, dp[j[0]-1]+[t])])
        if len(temp) == 0:
            dp[k] += dp[k-1]
            continue
        temp.sort(key=lambda x: x[2], reverse=True)
        temp.sort(key=lambda x:x[1])
        if temp[-1][1] > money(u_list, dp[k-1]):
            dp[k] += dp[u_list[temp[-1][0]][0]-1].copy() + [temp[-1][0]]
        elif temp[-1][1] == money(u_list, dp[k-1]):
            if get_days(u_list, dp[k-1]) < get_days(u_list, dp[u_list[temp[-1][0]][0]-1] + [temp[-1][0]]):
                dp[k] += dp[k - 1]
            else:
                dp[k] += dp[u_list[temp[-1][0]][0] - 1] + [temp[-1][0]]
        else:
            dp[k] += dp[k - 1]

    print(money(u_list, dp[u_list[-1][1]]), get_days(u_list, dp[u_list[-1][1]]))

main()