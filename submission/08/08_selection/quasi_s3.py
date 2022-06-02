import sys

str1 = sys.stdin.readline().rstrip()
str2 = sys.stdin.readline().rstrip()
DP = [[""]*(len(str2)+2) for i in range(len(str1)+2)]

for i in range(len(str1)):
    for j in range(len(str2)):
        if (str1[i]==str2[j]):
            for k in range(i,i+2):
                for m in range(j,j+2):
                    if (i==0 or j ==0):
                        if len(DP[k][m]) <= 1:
                            DP[k][m] = str1[i]
                    else:
                        if len(DP[k][m]) <= len((DP[i-1][j-1]+str1[i])):
                            DP[k][m] = DP[i-1][j-1] + str1[i]


result = ""
for i in range(len(DP)):
    for j in range(len(DP[i])):
        if (len(DP[i][j])) > len(result):
            result = DP[i][j]
        if (len(DP[i][j])) ==len(result):
            if (DP[i][j] < result):
                result = DP[i][j]

print(result)