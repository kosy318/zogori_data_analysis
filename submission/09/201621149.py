def cal2(A, B, o):
    res_list = []
    for a in A["b"], A["w"]:
        for b in B["b"], B["w"]:
            res_list.append(order[o](a, b))
    
    return max(res_list), min(res_list)

def cal(i, j):
    now = 0

    A = res_tower[now][j]
    B = res_tower[i-1-now][j+1+now]
    b, w = cal2(A, B, orders[j+now])
    now += 1

    while now < i:
        A = res_tower[now][j]
        B = res_tower[i-1-now][j+1+now]
        b2, w2 = cal2(A, B, orders[j+now])

        if b < b2:
            b = b2
        if w > w2:
            w = w2

        now += 1

    return {"b":b, "w":w}

my_string = input().split()
nums = [int(v) for idx, v in enumerate(my_string) if idx%2 == 0]
orders = [v for idx, v in enumerate(my_string) if idx%2 == 1]
order = {
    "+": lambda x, y: x + y,
    "-": lambda x, y: x - y,
    "–": lambda x, y: x - y,
    "*": lambda x, y: x * y,
}


len_orders = len(orders)

res_tower = [[{"w":0, "b":0} for _ in range(len(nums)-idx)] for idx in range(len(nums))]
for idx, n in enumerate(nums):
    res_tower[0][idx]["w"] = n
    res_tower[0][idx]["b"] = n

for i in range(1, len_orders+1):
    for j in range(len_orders-i+1):
        res_tower[i][j] = cal(i, j)

print(res_tower[-1][0]["b"])