import sys
from copy import copy
task_list=[]
N,T,K = map(int,sys.stdin.readline().split())
for _ in range(N):
    task_list.append(list(map(int,sys.stdin.readline().split())))
task_list.sort(reverse=True)


def maxProfit(task_li):
    profit_list = [[0] * T for _ in range(K)]
    selected_task=[]
    for i in range(N):
        break_ = False
        for j in range(T,0,-1):
            if break_==True:
                break
            for k in range(K):
                if profit_list[k][j-1]==0 and task_li[i][1] >= j:
                    profit_list[k][j-1]= task_li[i][0]
                    selected_task.append(i)
                    break_=True
                    break
    return profit_list,selected_task

def Profit(profit_list):
    sum=0
    for i in profit_list:
        for j in i:
            sum+=j
    return sum

def secProfit(task_list,selected_list):
    selected_list=list(reversed(selected_list))
    sec=0
    task_li =copy(task_list)
    for i in selected_list:
        task_li[i]=[0,0]
        temp=Profit(maxProfit(task_li)[0])
        if temp == max_profit:
            for j in range(N):
                if task_li[j][0]==task_list[i][0]:
                    task_li[j]=[0,0]
            temp=Profit(maxProfit(task_li)[0])
        if sec<temp and temp<max_profit:
            sec=temp

        task_li[i]=task_list[i]
    return sec


maxP=maxProfit(task_list)
max_profit=Profit(maxP[0])
selected_list= maxP[1]

sec_profit = secProfit(task_list,selected_list)

print(max_profit,sec_profit)
