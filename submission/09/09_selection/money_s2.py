def doCalc(a, b, ch):
    if ch == '+':
        return a + b
    elif ch == '-':
        return a - b
    elif ch == '*':
        return a * b

rows = 30
cols = 30
maxdp = [[0 for j in range(cols)] for i in range(rows)]
mindp = [[0 for j in range(cols)] for i in range(rows)]

num = []
oper = []
words = ' '.join(input().split())
values = words.split(" ")
li = []
for i in range(len(values)):
    if i % 2 == 0:
        num.append(int(values[i]))
    else:
        oper.append(values[i])

for i in range(len(num)):
    maxdp[i][i] = num[i]
    mindp[i][i] = num[i]


for i in range(len(oper)):
    maxdp[i][i + 1] = doCalc(maxdp[i][i], maxdp[i + 1][i + 1], oper[i])
    mindp[i][i + 1] = doCalc(mindp[i][i], mindp[i + 1][i + 1], oper[i])

for j in range(2, len(num)):
    for i in range(j-2, -1, -1):
        for k in range(0, j-i):
            li.append(doCalc(maxdp[i][i + k], maxdp[i + k + 1][j], oper[k + i]))
            li.append(doCalc(maxdp[i][i + k], mindp[i + k + 1][j], oper[k + i]))
            li.append(doCalc(mindp[i][i + k], mindp[i + k + 1][j], oper[k + i]))
            li.append(doCalc(mindp[i][i + k], maxdp[i + k + 1][j], oper[k + i]))
        maxdp[i][j] = max(li)
        mindp[i][j] = min(li)
        li.clear()

print(maxdp[0][len(num) - 1])