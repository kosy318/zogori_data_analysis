import sys
from collections import deque


def ruleCheck(s,t,cursor):

    if cursor == len(t):
        if len(s) % 2 == 1:
            return "YES"
    queue=deque([])
    for i,word in enumerate(s):
        if word == t[cursor] and (i%2 == 1):
            queue.append(i)
    while queue:
        finded = queue.popleft()
        s = s.replace(s[finded],'_',1)
        s= s[finded:]
        return ruleCheck(s,t,cursor+1)


def caseFinder(s,t):
    if (len(s)%2==1):
        if(len(t)%2==1):
            while s.find(t[0]) != -1:
                if s.find(t[0])%2==0:
                    s = list(s[s.find(t[0]):])
                    s[0] = '_'
                    s="".join(s)
                    if ruleCheck(s, t, 1) == "YES":
                        return "YES"
                s=s.replace(t[0],'_',1)
        else:
            while s.find(t[0]) != -1:
                if s.find(t[0])%2==1:
                    s = list(s[s.find(t[0]):])
                    s[0] = '_'
                    s="".join(s)
                    if ruleCheck(s, t, 1) == "YES":
                        return "YES"
                s=s.replace(t[0],'_',1)
    else:
        if (len(t)%2==1):
            while s.find(t[0]) != -1:
                if s.find(t[0])%2==1:
                    s = list(s[s.find(t[0]):])
                    s[0] = '_'
                    s="".join(s)
                    if ruleCheck(s, t, 1) == "YES":
                        return "YES"
                s=s.replace(t[0], '_', 1)
        else:
            while s.find(t[0]) != -1:
                if s.find(t[0])%2==0:
                    s = list(s[s.find(t[0]):])
                    s[0] = '_'
                    s="".join(s)
                    if ruleCheck(s, t, 1) == "YES":
                        return "YES"
                s=s.replace(t[0], '_', 1)

    return "NO"

n = int(sys.stdin.readline().rstrip())
for i in range(n):
    s=sys.stdin.readline().rstrip()
    t=sys.stdin.readline().rstrip()
    print(caseFinder(s,t))


"""
casefinder():
case1: s가 홀수개 이고 t가 홀수개이면 홀수 번째에서 시작해야함
case2: s가 홀수개 이고 t가 짝수개이면 짝수 번째에서 시작해야함
case3: s가 짝수개 이고 t가 홀수개이면 짝수 번째에서 시작해야함
case4: s가 짝수개 이고 t가 짝수개이면 홀수 번째에서 시작해야함

ruleCheck():
1.바로옆또는 두칸 간격이여야함
2.마지막글자뒤에는 짝수칸만큼 남아야함

"""