matrix = []
inputList = input().split()

num      = inputList[0::2]
operator = inputList[1::2]

N = len(num)

for i in range(0, N):
    array = [[] for _ in range(N)]
    array[i] = [num[i]]
    matrix.append(array)


for k in range(N-1, 0, -1):
    for i in range(0, k):
        j = i + (N-k)

        m = []

        for p in range(1, N-k+1):
            for a in matrix[i][j-p]:
                for b in matrix[i+(N-k+1-p)][j]:
                    m.append(eval(a+operator[j-p]+b))

        calMin = min(m)
        calMax = max(m)

        if i==0 and j==N-1:
            print(calMax)
            break

        if calMin == calMax:
            matrix[i][j] = [str(calMax)]
        else:
            matrix[i][j] = [str(calMin), str(calMax)]