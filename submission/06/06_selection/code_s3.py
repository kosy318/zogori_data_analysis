matrix = []
inputStr = input()
N = len(inputStr)

for i in range(N):
    array = ["" for _ in range(N)]
    array[i] = inputStr[i]
    matrix.append(array)

for k in range(N-1, 0, -1):
    for i in range(0, k):
        j = i + (N-k)
        if len(matrix[i][j-1]) == len(matrix[i+1][j]):
            matrix[i][j] = min(matrix[i][j-1], matrix[i+1][j])
        else:
            matrix[i][j] = max(matrix[i][j-1], matrix[i+1][j], key = lambda s: len(s))

        if matrix[i][i] == matrix[j][j]:
            matrix[i][j] = matrix[i][i] + matrix[i+1][j-1] + matrix[i][i]

print(matrix[0][N-1])