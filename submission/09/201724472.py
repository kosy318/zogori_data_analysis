import sys
def operand2(a, b, opera, mina, minb):
    if opera == '*':
        return max([a*minb, mina*b, mina*minb, a*b])
    elif opera == '-':
        return a-minb
    else:
        return a+b

def operand3(a, b, opera, mina, minb):
    if opera == '*':
        return min([a*minb, mina*b, mina*minb, a*b])
    elif opera == '-':
        return mina-b
    else:
        return mina+minb

def main():
    A = sys.stdin.readline().strip().split(' ')
    num = [int(v) for i,v in enumerate(A) if i%2==0]
    n = len(num)
    oper = [v for i,v in enumerate(A) if i%2!=0]
    dp_max = [[0 if i!=j else num[i] for i in range(n)] for j in range(n)]
    dp_min = [[0 if i!=j else num[i] for i in range(n)] for j in range(n)]

    for i in range(1, n):
        for j in range(i - 1, -1, -1):
            temp = []
            for l in range(j, i):
                #dp[j][l]
                temp.append(operand2(dp_max[j][l], dp_max[l+1][i], oper[l], dp_min[j][l], dp_min[l+1][i]))
                temp.append(operand3(dp_max[j][l], dp_max[l+1][i], oper[l], dp_min[j][l], dp_min[l+1][i]))
            dp_max[j][i] = max(temp)
            dp_min[j][i] = min(temp)

    print(dp_max[0][-1])
main()