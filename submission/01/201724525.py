import sys

def C2(word,L,R):
    while (L < R):
        if (word[L] == word[R]):
            L = L+1
            R = R-1
        else:
            return False
    return True


def C1(word,L,R):
    while (L < R):
        if (word[L] == word[R]):
            L = L+1
            R = R-1
        else:
            check1 = C2(word,L+1,R)
            check2 = C2(word,L,R-1)
            if(check1 or check2):
                return 2
            else:
                return 3
    return 1

n = int(sys.stdin.readline().rstrip("\n"))

for i in range(n):
    word = sys.stdin.readline().rstrip("\n")
    ans = C1(word,0,len(word)-1)
    print(ans)
