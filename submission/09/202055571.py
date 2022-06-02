s = input()
token = s.split()

operand = []
operator = []

for t in token:
    if (t == '-' or t == '*' or t == '+'):
        operator.append(t)
    else:
        operand.append(t)

minList = [[0]*len(operand) for _ in range(len(operand))]
maxList = [[0]*len(operand) for _ in range(len(operand))]

cnt = 0
while(cnt < len(operand)):
    i = 0
    j = cnt
    while (i < len(operand) and j < len(operand)):
        if (i == j):
            minList[i][j] = int(operand[i])
            maxList[i][j] = int(operand[i])
        else:
            temp = []            
            for k in range(j-i):
                temp.append(eval(str(minList[i][i+k]) + operator[i+k] + str(minList[i+k+1][j])))
                temp.append(eval(str(minList[i][i+k]) + operator[i+k] + str(maxList[i+k+1][j])))
                temp.append(eval(str(maxList[i][i+k]) + operator[i+k] + str(minList[i+k+1][j])))
                temp.append(eval(str(maxList[i][i+k]) + operator[i+k] + str(maxList[i+k+1][j])))
            minList[i][j] = min(temp)
            maxList[i][j] = max(temp)
            temp = []
        i += 1
        j += 1
    cnt += 1    

print(maxList[0][len(operand)-1])