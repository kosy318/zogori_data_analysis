import sys
import math

ROUNDING = 4


def calc(x, y, d):
    m = [0, 0, 0]

    while True:
        dist1, dist2 = 0, 0

        for i in range(3):
            m[i] = (x[i] + y[i]) / 2
            dist1 += (x[i] - d[i]) ** 2
            dist2 += (y[i] - d[i]) ** 2

        dist1 = round(dist1 ** 0.5, ROUNDING)
        dist2 = round(dist2 ** 0.5, ROUNDING)

        if dist1 == dist2:
            return m[:], dist1
        elif dist1 > dist2:
            x = m[:]
        else:
            y = m[:]


A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))
C = list(map(int, sys.stdin.readline().split()))
D = list(map(int, sys.stdin.readline().split()))

prev_distance1, prev_distance2 = 0, 1

while True:
    P1, P2, P3, P4 = A[:], B[:], C[:], D[:]

    D, temp = calc(P1, P2, D)
    D, distance = calc(P3, P4, D)

    if prev_distance1 == prev_distance2 == distance:
        result = math.ceil(distance)
        break

    prev_distance1, prev_distance2 = distance, distance

print(result)
