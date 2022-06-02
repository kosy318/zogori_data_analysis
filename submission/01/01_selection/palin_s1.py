import sys
inp = sys.stdin

def deterPalin(front,rear,isDif):
    while front<rear:
        if s[front]==s[rear]:
            front += 1
            rear -= 1
            continue
        if isDif:
            return 3
        if deterPalin(front+1,rear,1) == 1 or deterPalin(front,rear-1,1) == 1:
            return 2
        return 3
    return 1
        
N = int(inp.readline())
for i in range(N):
    s = inp.readline().rstrip()
    print(deterPalin(0,len(s)-1,0))