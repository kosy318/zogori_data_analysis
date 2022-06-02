import re
def solution():
  answer_list = []
  N = int(input())
  for _ in range(N):
    t = input().lower()
    s = input().lower()
    length_t = len(t)
    length_s = len(s)
    t = re.sub(r'[^a-z]', '', t)
    s = re.sub(r'[^a-z]', '', s)
    #exception handling
    if length_s > length_t:
      answer_list.append("NO")
      continue
    if t == s:
      answer_list.append("YES")
      continue
    if t[1:] == s:
      answer_list.append("YES")
      continue

    find_list = [n for n, e in enumerate(t) if s[0] == e]
    if len(find_list) == 0:
      answer_list.append("NO")
      continue
    is_true = False
    for k in find_list:
      is_true |= find_same(s[1:], t, k)

    if is_true:
      answer_list.append("YES")
    else:
      answer_list.append("NO")

  for answer in answer_list:
    print(answer)

def find_same(ss, tt, kk):
  check = False
  if ss == '' and len(tt[kk:])%2 != 0 :
    return True
  if len(ss) == 0:
    return False
  find_list = [n for n,e in enumerate(tt) if n > kk and ss[0] == e and (n-kk)%2 == 1]
  if len(find_list) == 0:
    return False
  for k in find_list:
    check |= find_same(ss[1:], tt, k)
    if check == False:
      return False
  return check






solution()

