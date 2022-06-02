def binary_search(target, data):
    l = 0
    r = len(data) - 1

    while(l <= r) :
        mid = (l + r) // 2
        if(data[mid][0] == target):
            return mid 
        elif(data[mid][0] < target):
            l = mid + 1
        else:
            r = mid -1
    if(r != -1) :
        return r
    else :
        return None

n = int(input())

l = []
D_v = [0] * n
D_d = [0] * n
for x in range(n) :
    line = list(map(int,input().split()))
    temp = line[0]
    line[0] = line[1]
    line[1] = temp
    l.append(line)
l.sort() 

D_v[0] = l[0][2]
D_d[0] = l[0][0] - l[0][1] + 1

for x in range(1,n) :
    A = D_v[x-1]
    temp = 0
    for y in range(x) :
        if(l[x][1] > l[y][0]) :
            continue
        else :
            B = y-1
            temp = 1
            break
    if(temp == 0) :
        B = x-1
    
    if(B == -1) :
        C = l[x][2]
    else :
        C = D_v[B] + l[x][2] - 10
    if(A > C) :
        D_v[x] = A
        D_d[x] = D_d[x-1]
    elif(A < C) :
        D_v[x] = C
        if(B != -1) :
            D_d[x] = D_d[B] + l[x][0] - l[x][1] + 1
        else :
            D_d[x] = l[x][0] - l[x][1] + 1
            
    else :
        D_v[x] = A
        if(B != -1) :
            D_d[x] = min(D_d[x-1],D_d[B] + l[x][0] - l[x][1] + 1)
        else :
            D_d[x] = min(D_d[x-1],l[x][0] - l[x][1] + 1)
       

max = max(D_v)
min = 99999999

for x in range(n) :
    if(D_v[x] == max and D_d[x] < min) :
        min = D_d[x]

print(max,min)
    


    
