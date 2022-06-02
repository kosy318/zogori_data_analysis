import sys

exp = sys.stdin.readline().split(' ')
operand = []
operator = []
for i in range(len(exp)):
    if i%2:
        operator.append(exp[i])
    else:
        operand.append(int(exp[i]))

res = [[(0,0) for _ in range(len(operand))] for __ in range((len(operand)))]

for i in range(len(operand)-1,-1,-1):
    res[i][i] = (operand[i],operand[i])
    for j in range(i+1,len(operand)):
        max_value,min_value = -9**30,9**30
        for k in range(i,j):
            aM,am = res[i][k]
            bM,bm = res[k+1][j]
            res1 = eval(str(aM)+operator[k]+str(bM))
            res2 = eval(str(am)+operator[k]+str(bm))
            res3 = eval(str(aM)+operator[k]+str(bm))
            res4 = eval(str(am)+operator[k]+str(bM))
            max_value = max(max_value,res1,res2,res3,res4)
            min_value = min(min_value,res1,res2,res3,res4)
        res[i][j] = (max_value,min_value)

print(res[0][len(operand)-1][0])