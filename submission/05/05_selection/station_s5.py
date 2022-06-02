from math import sqrt, ceil, floor

inp = [list(map(int, input().strip().split())) for _ in range(4)]
A, B, C, D = inp


def binary_search_P(left, right):
    global answer, P, Q

    mid = (left + right) / 2
    P = [A[i] * mid + B[i] * (1-mid) for i in range(3)]
    p_left = [A[i] * (mid-tmp) + B[i] * (1-mid+tmp) for i in range(3)]
    p_right = [A[i] * (mid+tmp) + B[i] * (1-mid-tmp) for i in range(3)]
    distance = sum(map(lambda x, y: (x-y)**2, P, Q))
    left_distance = sum(map(lambda x, y: (x-y)**2, p_left, Q))
    right_distance = sum(map(lambda x, y: (x-y)**2, p_right, Q))

    answer = min(answer, distance, left_distance, right_distance)

    if left + tmp >= right:
        return answer

    if left_distance < distance:
        answer = min(answer, binary_search_P(left, mid))
    else:
        answer = min(answer, binary_search_P(mid, right))

    return answer


def binary_search_Q(left, right):
    global answer, P, Q

    mid = (left + right) / 2
    Q = [C[i] * mid + D[i] * (1-mid) for i in range(3)]
    q_left = [C[i] * (mid-tmp) + D[i] * (1-mid+tmp) for i in range(3)]
    q_right = [C[i] * (mid+tmp) + D[i] * (1-mid-tmp) for i in range(3)]
    distance = sum(map(lambda x, y: (x-y)**2, Q, P))
    left_distance = sum(map(lambda x, y: (x-y)**2, q_left, P))
    right_distance = sum(map(lambda x, y: (x-y)**2, q_right, P))

    answer = min(answer, distance, left_distance, right_distance)

    if left + tmp >= right:
        return answer

    if left_distance < distance:
        answer = min(answer, binary_search_Q(left, mid))
    else:
        answer = min(answer, binary_search_Q(mid, right))

    return answer


P, Q = A, C
tmp = 1/100000000

answer = float('INF')
result = float('INF')

while True:
    answer = min(answer, binary_search_P(0, 1), binary_search_Q(0, 1))
    if answer < result:
        result = answer
    else:
        break

if result - floor(result) < tmp:
    result = floor(result)

print(ceil(sqrt(result)))