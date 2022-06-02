import sys
import copy
def h(array):
    a2 = []
    if len(array) == 1:
        return 1
    else:
        l = len(array)//2
        for i in range(l):
            a2.append(array.pop())
        for j in range(len(a2)):
            if array[j] != a2[j]:
                return (h2(a2))
        else:
            return 1
def h2(a2):
    for k in range(len(c)):
        a3 = copy.deepcopy(c)
        del a3[k]
        a4 = []
        l = len(a3)//2
        for w in range(l):
            a4.append(a3.pop())
        for j in range(len(a4)):
            if a3[j] != a4[j]:
                break
        else:
            return 2
    return 3
n = int(sys.stdin.readline().strip())
for a in range(n):
    array = list(sys.stdin.readline().strip())
    c = copy.deepcopy(array)
    print(h(array))