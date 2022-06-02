def calc(n1, n2, op):
    if op=='+':
        return n1+n2
    elif op=='-':
        return n1-n2
    return n1*n2

def max(n1, n2, n3, n4):
    ret = n2 if n1<n2 else n1
    if ret<n3:
        ret=n3
    if ret<n4:
        ret=n4
    return ret

def min(n1, n2, n3, n4):
    ret = n2 if n1>n2 else n1
    if ret>n3:
        ret=n3
    if ret>n4:
        ret=n4
    return ret

def main():
    numbers = []
    operators = []
    maxTable = []
    minTable = []
    inputstr = input()
    for c in inputstr.split():
        if c=='+' or c=='-' or c=='*':
            operators.append(c)
        else:
            numbers.append(int(c))


    for i in range(len(numbers)):
        emptylist1 = []
        emptylist2 = []
        for j in range(len(numbers)):
            emptylist1.append(0)
            emptylist2.append(0)
        maxTable.append(emptylist1)
        minTable.append(emptylist2)

    for i in range(len(numbers)):
        for j in range(len(numbers)-i):
            if i==0:
                maxTable[j][j] = numbers[j]
                minTable[j][j] = numbers[j]
            else:
                first = False;
                for k in range(j,(j+i)):
                    op = operators[k]
                    maxnum = max(calc(maxTable[j][k], maxTable[k + 1][j + i], op), calc(maxTable[j][k], minTable[k + 1][j + i], op), calc(minTable[j][k], maxTable[k + 1][j + i], op), calc(minTable[j][k], minTable[k + 1][j + i], op));
                    minnum = min(calc(maxTable[j][k], maxTable[k + 1][j + i], op), calc(maxTable[j][k], minTable[k + 1][j + i], op), calc(minTable[j][k], maxTable[k + 1][j + i], op), calc(minTable[j][k], minTable[k + 1][j + i], op));
                    if first==False:
                        first = True
                        maxTable[j][j+i] = maxnum
                        minTable[j][j+i] = minnum
                    else:
                        if maxTable[j][j+i] < maxnum:
                            maxTable[j][j+i] = maxnum
                        if minTable[j][j+i] > minnum:
                            minTable[j][j+i] = minnum 
    
    print(maxTable[0][len(numbers)-1])

if __name__ == "__main__":
    main()
