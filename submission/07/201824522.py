import sys
inp = sys.stdin.readline

N = int(inp())
memo = [(0,0)]*1096

def dp(day):
    if day < opening:
        return (10,0)

    if memo[day]!=(0,0):
        return memo[day]

    if cleans[day]:
        max_cost,min_days = 0,ending
        for start,cost in cleans[day]:
            cur_cost,cur_days = (lambda x: (x[0]+cost-10,x[1]+day-start+1) )(dp(start-1))
            if cur_cost > max_cost:
                max_cost,min_days = cur_cost,cur_days
            elif cur_cost == max_cost:
                min_days = min(min_days,cur_days)
        
        yester_cost, yester_days = dp(day-1)
        if yester_cost > max_cost:
            memo[day] = (yester_cost,yester_days)
        elif yester_cost == max_cost:
            memo[day] = (yester_cost, min(yester_days,min_days))
        else:
            memo[day] = (max_cost,min_days)
        return memo[day]

    for i in range(day-1,opening-1,-1):
        if cleans[i]:
            memo[day] = dp(i)
            return memo[day]

    memo[day] = (10,0)
    return memo[day]

cleans = [[]for _ in range(1096)]
opening, ending = 1096,0

for _ in range(N):
    b,e,c = map(int,inp().split())
    opening = min(opening,b)
    ending = max(ending,e)
    cleans[e].append((b,c))

print(*dp(ending))