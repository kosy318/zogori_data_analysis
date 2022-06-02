def isEven(n):
    return n%2 == 0

def back(s, t):
    len1 = len(s)
    len2 = len(t)
    
    if len1 < len2:
        return False
    elif len1 == len2:
        return s == t
    elif not isEven(len1-len2):
        return back(s[1:], t)
    
    idx = [0 for i in range(len2)]
    
    cnt = 0
    for i in range(len1):
        if t[cnt] == s[i]:
            idx[cnt] = i;
            if (cnt > 0) and isEven(idx[cnt]-idx[cnt-1]):
                return back(s[idx[cnt-1]+1:], t)
            cnt = cnt+1
        if cnt >= len2:
            if isEven(len1 - idx[cnt-1]):
                return back(s[idx[0]+1:], t)
            break
    
    if cnt >= len2:
        return True
    else:
        return False

n = int(input(""))

for i in range(n):
  s = input("")
  t = input("")
  if back(s, t):
    print("YES")
  else:
    print("NO")