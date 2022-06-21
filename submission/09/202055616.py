
from posixpath import split

global num
global op
num=[]
op=[]


def Input():
    global num
    global op

    str = input()

    str = str.split()

    cnt =0
    for i in range(0,len(str)):
        if cnt%2 == 0:

            num.append(int(str[i]))
        else:
            op.append(str[i])
        cnt +=1


def Cal(num1, num2, ch):

    if(ch == '+'):
        return num1 + num2
    elif(ch == '-'):
        return num1 - num2
    else:
        return num1 * num2

def Table():
    global num
    global op


    table=[ [00] *len(num) for _ in range(len(num))]
    temp=[]

    for i in range(0,len(num)):
        x =[num[i],num[i]]
        table[i][i]=x

        if(i+1 != len(num)):
            base = Cal(num[i],num[i+1],op[i])
            table[i][i+1]=[base,base]



    k = 2
    i = 0
    j = k

    while(i+j != len(num)):
        while(j != len(num)):
            ii = j
            jj = j-1

            for w in range(0,k):
                num1_max = table[i][jj][0]
                num1_min = table[i][jj][1]
                num2_max = table[ii][j][0]
                num2_min = table[ii][j][1]

                temp.append(Cal(num1_max,num2_max,op[jj]))
                temp.append(Cal(num1_max,num2_min,op[jj]))
                temp.append(Cal(num1_min,num2_max,op[jj]))
                temp.append(Cal(num1_min,num2_min,op[jj]))

                ii-=1
                jj-=1


            Max = max(temp)
            Min = min(temp)

            table[i][j]=[Max,Min]

            temp.clear()
            i+=1
            j+=1

        k+=1
        i=0
        j=k
    return table

def main():
    global num
    Input()

    table = Table()
    print(table[0][len(num)-1][0])

main()

