import numpy as np

if __name__=="__main__":
    n = int(input())
    daily = np.zeros((n, 3), dtype=np.int32)
    
    for i in range(n):
        data = input().split()
        daily[i] = [int(d) for d in data]
    
    idx = daily[:, 1].argsort()
    daily[:, :] = daily[idx, :]
    
    end_day = daily[:, 1].max(axis=0)
    dp = np.zeros((end_day+1, 2), dtype=np.int32)
    
    for i in range(n):
        s = daily[i, 0]
        e = daily[i, 1]
        cost = daily[i, 2]
        
        a = dp[s:e+1, 0].argmax()
        b = dp[0:s, 0].argmax()
        
        if (dp[s+a, 0] > dp[b, 0] - 10 + cost):
            dp[e, :] = dp[s+a, :]
        else:
            if (dp[b, 0] == 0):
                dp[e, 0] = cost
            else:
                dp[e, 0] = dp[b, 0] - 10 + cost
            dp[e, 1] = dp[b, 1] + (e-s+1)
    
    result = dp[:, 0].argmax()
    print(dp[result, 0], dp[result, 1])
    print('\n')