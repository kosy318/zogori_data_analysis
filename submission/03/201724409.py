from copy import deepcopy
N = int(input().rstrip())

def flip(a, start, end):
    tmp = a[start:end]
    tmp = tmp[::-1]
    for i in range(start, end):
        a[i] = -tmp[i-start]


def findleft():
    start, end = -1, -1
    for i in range(N):
        if start == -1:
            if arr[i] == -(i+1):
                flip(arr, i, i+1)
                return

            if abs(arr[i]) != i+1:
                start = i

        elif start != -1 and abs(arr[i]) == start+1:
            end = i+1
            break

    flip(arr, start, end)


def findright():
    start, end = N, N
    for i in range(N-1, -1, -1):
        if end == N:
            if arr2[i] == -(i+1):
                flip(arr2, i, i+1)
                return

            if abs(arr2[i]) != i+1:
                end = i

        elif end != N and abs(arr2[i]) == end+1:
            start = i+1
            break

    flip(arr2, start-1, end+1)


for _ in range(5):
    arr = list(map(int, input().strip().split()))
    arr2 = deepcopy(arr)
    mask = [i for i in range(1, N+1)]

    for leftanswer in range(4):
        if leftanswer == 3 or arr == mask:
            break
        findleft()


    for rightanswer in range(4):
        if rightanswer == 3 or arr2 == mask:
            break
        findright()

    answer = min(leftanswer, rightanswer)
    result = ["zero", "one", "two", "over"]
    print(result[answer])

print()