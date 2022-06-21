def word(i, j):
    L = ""

    if i == 0 or j == 0:
        return L
    while i * j > 0:
        if ref_score(i, j)["inline"]:
            L += S[i-1]
        i, j = ref_score(i, j)["before"]
        
    return L[::-1]


def check(A:tuple, B:tuple):
    if ref_score(*A)["len"] > ref_score(*B)["len"]:
        return 0
    elif ref_score(*A)["len"] < ref_score(*B)["len"]:
        return 1
    
    if word(*A) < word(*B):
        return 0
    return 1


S, T = input(), input()

score = [
    [
        {
            "len":0, 
            "before": (0,0),
            "inline": False
        } 
        for _ in range(len(T)+1)
    ] for __ in range(len(S)+1)
]

ref_score = lambda x, y: score[x][y]
res = {
    "len":0,
    "list": []
}


for idx_s, s in enumerate(S, 1):
    for idx_t, t in enumerate(T, 1):
        if s == t:
            AB = ((idx_s-1, idx_t-1), (idx_s-2, idx_t-2))
            condition = 0
            if idx_s > 1 and idx_t > 1 and ref_score(*AB[1])["inline"]:
                condition = check(*AB)

            score[idx_s][idx_t]["len"] = ref_score(*AB[condition])["len"]+1
            score[idx_s][idx_t]["before"] = AB[condition]
            score[idx_s][idx_t]["inline"] = True

            if res["len"] < ref_score(idx_s, idx_t)["len"]:
                res["len"] = ref_score(idx_s, idx_t)["len"]
                res["list"] = [(idx_s, idx_t)]
            elif res["len"] == ref_score(idx_s, idx_t)["len"]:
                res["list"].append((idx_s, idx_t))


        else:
            AB = ((idx_s-1, idx_t), (idx_s, idx_t-1))
            condition = 2
            if ref_score(idx_s-1, idx_t)["inline"]:
                if ref_score(idx_s, idx_t-1)["inline"]:
                    condition = check(*AB)
                else:
                    condition = 0
            elif ref_score(idx_s, idx_t-1)["inline"]:
                condition = 1
            
            if condition == 2:
                continue
            score[idx_s][idx_t]["len"] = ref_score(*AB[condition])["len"]
            score[idx_s][idx_t]["before"] = AB[condition]


res_L = word(*res["list"][0])
for w in res["list"][1:]:
    res_L = min(res_L, word(*w))

print(res_L)