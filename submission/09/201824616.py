s = input()
m = False
num = []
op = []

for i in range(len(s)):
    if s[i] >= '0' and s[i] <= '9':
        if m == True:
            num.append(-(int(s[i])))
            m = False
        else :
            num.append(int(s[i]))
    elif s[i] == '+' or s[i] == '*':
        op.append(s[i])
    elif s[i] == '-':
        if s[i + 1] == ' ':
            op.append(s[i])
        else: 
            m = True

n = len(num)
arr_max = [[-(9 ** 30) - 1] * n for i in range(n)]
arr_min = [[9 ** 30 + 1] * n for i in range(n)]

for i in range(n):
    arr_max[i][i] = num[i]
    arr_min[i][i] = num[i]

def assign_arr(x, y):
    for i in range(y, x):
        if op[i] == '+':
            op_max = arr_max[y][i] + arr_max[i + 1][x]
            op_min = arr_min[y][i] + arr_min[i + 1][x]
        elif op[i] == '-':
            op_max = arr_max[y][i] - arr_min[i + 1][x]
            op_min = arr_min[y][i] - arr_max[i + 1][x]
        elif op[i] == '*':
            op_max = max([arr_max[y][i] * arr_max[i + 1][x], arr_min[y][i] * arr_min[i + 1][x]])
            op_min = min([arr_max[y][i] * arr_min[i + 1][x], arr_min[y][i] * arr_max[i + 1][x], arr_min[y][i] * arr_min[i + 1][x]])
        
        if arr_max[y][x] < op_max:
            arr_max[y][x] = op_max
        if arr_min[y][x] > op_min:
            arr_min[y][x] = op_min

for i in range(1, n):
    k = 0
    for j in range(i, n):
        assign_arr(j, k)
        k += 1

print(arr_max[0][n - 1])