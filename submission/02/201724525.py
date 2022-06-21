
def lastone(L,le):
    i=0
    a=[]
    if L ==[]:
        return a
    while i<len(L[len(L)-1]):
        if (le - L[len(L)-1][i])%2 ==0:
            i = i+1
        else:
            a.append(L[len(L)-1][i])
            i = i+1
    return a

def numcheck(L1,L2):
    i=0
    a=[]
    if L1 ==[]:
        return a
    if L1[0]%2 ==1:
        while i<len(L2):
            if L2[i]%2 == 0:
                a.append(L2[i])
            i = i+1
    else:
        while i<len(L2):
            if L2[i]%2 == 1:
                a.append(L2[i])
            i = i+1
    return a

def resort(i,k):
    j=0
    if len(TL)<2:
        return True
    while j<len(TL[k]):
        if i<TL[k][j]:
            break
        else:
            j = j+1
    if j==len(TL[k]):
        return False
    else:
        ii = TL[k][j]
        k = k+1
        if k==len(TL):
            return True
        else:
            return resort(ii,k)

num = int(input())
i=0
s1=[]


while i<num:
    line = ''.join(filter(str.isalnum, input()))
    s = list(line)
    line = ''.join(filter(str.isalnum, input()))
    t = list(line)
    k=0    
    TL = []
    while k<len(t):
        j=0
        TL.append([])
        while j<len(s):
            if t[k] ==s[j]:
                TL[k].append(j)
            j = j+1
        k = k+1
    j= len(TL) -1
    if TL ==[]:
        print("YES")
    else:
        TL[len(TL)-1] =  lastone(TL,len(s))
        
        while j>0:
            TL[j-1] = numcheck(TL[j],TL[j-1])
            j = j-1
        if [] in TL:
            print("NO")
        else:
            if resort(TL[0][0],1):
                print("YES")
            else:
                print("NO")
    i = i+1