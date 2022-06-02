from numpy import linspace
from math import ceil

def calcultae_length(a, b):
    return sum([(a[i]-b[i])**2 for i in range(3)])

line = [tuple(map(int, input().split())) for _ in range(4)]
vec = [[line[j*2+1][i] - line[j*2][i] for i in range(3)] for j in range(2)]
vec_xyz = [[tuple(v1/v2 for v1 in vec[i]) if v2 else None for v2 in vec[i]] for i in range(2)]

compo = [0, 0]
for i in range(2):
    for idx, li in enumerate(vec_xyz[i]):
        if li:
            compo[i] = idx

vec_func = lambda x, idx:[line[idx*2][i] + x * vec_xyz[idx][compo[idx]][i] for i in range(3)]

SIZE = [abs(line[idx*2+1][compo[idx]] - line[idx*2][compo[idx]]) for idx in range(2)]

for i in range(2):
    while SIZE[i] < 20000:
        SIZE[i] *= 2
    SIZE[i] += 1

point_list = [linspace(0, line[i*2+1][compo[0]]-line[i*2][compo[0]], SIZE[i]) for i in range(2)]

p = [0, 0]
before_p = [-1, -1]
point = [vec_func(point_list[idx][p[idx]], idx) for idx in range(2)]

val = {"i":None, "j":None}

def calculating(idx):
    i, j = 0, SIZE[idx]-1
    size = SIZE[idx]
    val["i"] = calcultae_length(vec_func(point_list[idx][i], idx), point[1-idx])
    val["j"] = calcultae_length(vec_func(point_list[idx][j], idx), point[1-idx])
    
    if val["i"] > val["j"]:
        size = j - i + 1
        i += size//2
        val["i"] = None
    else:
        size = j - i + 1
        j -= size//2
        val["j"] = None

    while i < j:
        if val["i"] != None:
            val["j"] = calcultae_length(vec_func(point_list[idx][j], idx), point[1-idx])
        else:
            val["i"] = calcultae_length(vec_func(point_list[idx][i], idx), point[1-idx])
        
        # print(val)
        if val["i"] > val["j"]:
            size = j - i + 1
            i += size//2
            val["i"] = None
        else:
            size = j - i + 1
            j -= size//2
            val["j"] = None

    if val["i"]: p1 = i
    else: p1 = j

    return p1

while (True):
    p[0] = calculating(0)
    point[0] = vec_func(point_list[0][p[0]], 0)
    p[1] = calculating(1)
    point[1] = vec_func(point_list[1][p[1]], 1)


    if p[:] == before_p[:]:
        break
    before_p[:] = p[:]

res = val["i"]

if res == None:
    res = val["j"]
print(ceil(res**0.5))
print()