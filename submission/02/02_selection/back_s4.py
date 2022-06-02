import sys

std = sys.stdin
# std = open('./sample_data02/05.inp','r')

def back(si,ti):
    if ti==len(t):
        return False if (len(s)-si)%2 else True

    for i in range(si,len(s)):
        if s[i] == t[ti]:
            if (not ti or (si-i-1)%2) and back(i+1,ti+1):
                return True
    return False



N = int(std.readline())
for i in range(N):
    s = std.readline().rstrip()
    t = std.readline().rstrip()

    print("YES" if back(0,0) else "NO")