import sys

S = sys.stdin.readline().rstrip()
T = sys.stdin.readline().rstrip()

def com_str(str1, str2):
    return min(str1,str2) if len(str1)==len(str2) else max(str1,str2,key=len)

quasi = [['' for _ in range(len(S)+1)] for __ in range(len(T)+1)]
max_str = ''

for i in range(max(len(S),len(T))):
    if i<len(T) and S[0] == T[i]:
        quasi[i+1][1] = S[0]
    if i<len(S) and T[0] == S[i]:
        quasi[1][i+1] = T[0]

for i in range(2,len(T)+1):
    for j in range(2,len(S)+1):
        if T[i-1]==S[j-1]:
            quasi[i][j] = com_str(com_str(quasi[i-1][j-1],quasi[i-2][j-2]),com_str(quasi[i-1][j-2],quasi[i-2][j-1]))
            quasi[i][j] += T[i-1]
        max_str = com_str(quasi[i][j],max_str)

print(com_str(max_str,T[-1]))