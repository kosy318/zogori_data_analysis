from copy import deepcopy

def check(A:dict, B:dict):
    if A["money"] > B["money"]:
        return True
    if A["money"] < B["money"]:
        return False
    if A["true_days"] < B["true_days"]:
        return True
    return False


N = int(input())

order = [list(map(int, input().split())) for _ in range(N)]
order.sort(key=lambda x: (x[0], x[1]))

# print("=============")
init_state = {
    "money":0,
    "true_days":0
}
res = {
    1:deepcopy(init_state)
}

day_now = 1
for od in order:
    # print(*od)
    start_day = od[0]
    end_day = od[1]+1
    earn_money = od[2]

    if day_now < start_day:
        while (day_now != start_day):
            day_now += 1
            if not res.get(day_now):
                res[day_now] = deepcopy(res[day_now-1])
            else:
                if check(res[day_now-1], res[day_now]):
                    res[day_now] = deepcopy(res[day_now-1])

    if not res.get(end_day):
        res[end_day] = deepcopy(init_state)
    
    work_result = deepcopy(init_state)
    
    if res[start_day]["money"]:
        work_result["money"] += res[start_day]["money"] + earn_money - 10
    else:
        work_result["money"] += res[start_day]["money"] + earn_money

    work_result["true_days"] += res[start_day]["true_days"] + end_day - start_day

    if check(work_result, res[end_day]):
        res[end_day] = work_result

while (day_now < max(res.keys())):
    day_now += 1
    if not res.get(day_now):
        res[day_now] = deepcopy(res[day_now-1])
    else:
        if check(res[day_now-1], res[day_now]):
            res[day_now] = deepcopy(res[day_now-1])

# print("RES")
# for k, v in sorted(res.items()):
#     print(f"{k}: {v}")
# print(day_now, res[day_now])
print(*res[day_now].values())