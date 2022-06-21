import sys

std = sys.stdin
# std = open('./sample_data03/05.inp')

def simpleFlip(string):
    isflipped = 0
    k = 1
    until = 0
    for i in range(1,N+1):
        if i <= until:
            if k!=string[i]:
                return 0
            k += 1
            if i == until:
                until = 0
                k = i+1
        elif i != string[i]:
            if string[i] > 0:
                return 0
            isflipped+=1
            until = -string[i]
            k = string[i] + 1
            continue
    return isflipped

def flip(string,i,j):
    string[i:j+1] = [-string[k] for k in range(j,i-1,-1)]
    return string

N = int(std.readline())
for _ in range(5):
    s = [0]+list(map(int,std.readline().split()))

    res = simpleFlip(s)    
    if res == 1:
        print('one')
        continue
    elif res == 2:
        print('two')
        continue
    elif res > 2:
        print('over')
        continue
    
    how = [0]*(N+1)
    set1 = set()
    set2 = set()
    block1 = block2 = 0
    for i in range(1,N+1):
        if i != s[i]:
            if s[i]<0:
                how[i] = 1
                set1.add(i)
            else:
                how[i] = 2
                set2.add(i)

    if not len(set2):
        if simpleFlip(flip(s,min(set1),max(set1))) == 1:
            print('two')
        else:
            print('over')
        continue

    if len(set1):
        if min(set1)<min(set2) and max(set1)>max(set2):
            if simpleFlip(flip(s,min(set1),max(set1))) == 1:
                print('two')
            else:
                print('over')
            continue
    
    left = min(set2)
    right = left
    for i in range(left+1,N+1):
        if how[i] == 2:
            right += 1
            continue
        if how[i] == 1:
            if -s[i]==left:
                break
            continue
        if not how[i]:
            break

    if simpleFlip(flip(s[:],left,i)) == 1:
        print('two')
        continue
    
    for i in range(right,-1,-1):
        if how[i] == 1:
            if -s[i] == right:
                break
            continue
        if not how[i]:
            break
    if simpleFlip(flip(s,i,right)) == 1:
        print('two')
    else:
        print('over')