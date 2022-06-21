def operate(l, r,op1,pn1,nn1):
    ll=l
    rr=l+1
    tmp=[]
    for i in range(r-l):
        if(op1[ll]=="+"):
            tmp.append(pn1[l][ll] + pn1[rr][r])
            tmp.append(pn1[l][ll] + nn1[rr][r])
            tmp.append(nn1[l][ll] + pn1[rr][r])
            tmp.append(nn1[l][ll] + nn1[rr][r])
        elif(op1[ll]=="-"):
            tmp.append(pn1[l][ll] - pn1[rr][r])
            tmp.append(pn1[l][ll] - nn1[rr][r])
            tmp.append(nn1[l][ll] - pn1[rr][r])
            tmp.append(nn1[l][ll] - nn1[rr][r])
        elif(op1[ll]=="*"):
            tmp.append(pn1[l][ll] * pn1[rr][r])
            tmp.append(pn1[l][ll] * nn1[rr][r])
            tmp.append(nn1[l][ll] * pn1[rr][r])
            tmp.append(nn1[l][ll] * nn1[rr][r])
        ll+=1
        rr+=1

    tmp=list(map(int,tmp))
    pn1[l][r]=max(tmp)
    nn1[l][r]=min(tmp)
    return

def maketable(nindex, num1,op1,pn1,nn1):
    nindex=int(nindex)
    for i in range(nindex):
        pn[i][i]=int(num1[i])
        nn[i][i]=int(num1[i])
    cnt=nindex-1
    n=1
    row=0
    col=row+n
    while(1):
        if(cnt==-1): break
        for i in range(cnt):
            operate(row,col,op1,pn1,nn1)
            row+=1
            col+=1
        n+=1
        row=0
        col=row+n
        cnt-=1
    return

pn=[[0 for col in range(31)] for row in range(31)]
nn=[[0 for col1 in range(31)] for row1 in range(31)]
num=[0]*31
op=[""]*31
s=input()
s=s.split(' ')
index=0
index2=0
for i in range(len(s)):
    if(i%2==0):
        num[index]=s[i]
        index+=1
    else:
        op[index2]=s[i]
        index2+=1

maketable(index,num,op,pn,nn)
print(pn[0][index-1])