from queue import PriorityQueue
def get_priority(str1, str2):
    len1, len2 = len(str1), len(str2)
    winner = max(len1, len2)
    pq = PriorityQueue(maxsize=2)
    pq.put(str1)
    pq.put(str2)

    ret = ''
    for _ in range(3):
        ret = pq.get()
        if winner == len(ret):
            return ret
    return ret

s = input()
length = len(s)
dp = [["" for _ in range(length)] for _ in range(length)]
for i in range(length):
    dp[i][i] = s[i]

for i in range(1, length):
    for y in range(length):
        x = y + i
        if x < length:
            if s[y] == s[x]:
                dp[y][x] = s[y] + dp[y+1][x-1] + s[x]
            else:
                dp[y][x] = get_priority(dp[y][x-1], dp[y+1][x])

print(dp[0][length-1])
