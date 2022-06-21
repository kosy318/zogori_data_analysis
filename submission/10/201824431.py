import numpy as np

if __name__=="__main__":
    N, T, k = input().split(' ')
    N = int(N)
    T = int(T)
    k = int(k)
    
    cost = np.zeros((N,), dtype=np.int32)
    due = np.zeros((N,), dtype=np.int32)
    solved = np.full((N,), False)
    
    for i in range(N):
        temp = input().split(' ')
        cost[i] = int(temp[0])
        due[i] = int(temp[1])
    
    machine = np.zeros((k, T), dtype=np.int32)
    
    # i = due.argsort()
    # due = due[i]
    # cost = cost[i]
    # print(due)
    # print(cost)
    
    max_profit = 0
    
    for date in range(T-1, -1, -1):
        for mi in range(k):
            max_cost = -1
            max_task = -1
            for task in range(N):
                if (solved[task] == False and date+1 <= due[task]):
                    if (cost[task] > max_cost):
                        max_cost = cost[task]
                        max_task = task
            
            if (max_cost > 0):
                machine[mi, date] = max_task
                solved[max_task] = True
                max_profit += max_cost
    
    #print(solved)
    #print(machine)
    s = np.array(np.where(solved == False))
    
    second_list = []
    min_val = 101
    for date in range(T):
        for mi in range(k):
            for i in s[0]:
                if (date+1 <= due[i] and cost[machine[mi, date]] > cost[i]):
                    second_list.append(max_profit - cost[machine[mi, date]] + cost[i])
    
            if (min_val > cost[machine[mi, date]]):
                min_val = cost[machine[mi, date]]
    
    second_list.append(max_profit - min_val)
    
    second_profit = max_profit
    if (0 < max(second_list) < second_profit):
        second_profit = max(second_list)
    
    print(max_profit, second_profit)