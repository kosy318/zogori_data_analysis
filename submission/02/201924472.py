import sys


def is_possible(s, t):
    if len(s) < len(t):
        return False
    elif len(s) == len(t):
        return s == t
    else:
        return calc(s, t)


def calc(s, t):
    omega = 0
    t_length = len(t)
    index = -1

    for i in range(len(s) - 1, -1, -2):
        try:
            j = i - omega
            if t[index] == s[j]:
                index -= 1
                omega = (omega + 1) % 2
                if t[index] == s[j - 1]:
                    index -= 1
                    omega = (omega + 1) % 2
        except IndexError:
            continue

    return abs(index) == t_length + 1


n_ = int(input())

for _ in range(n_):
    s_ = sys.stdin.readline().rstrip()
    t_ = sys.stdin.readline().rstrip()

    if is_possible(s_, t_):
        print("YES")
    else:
        print("NO")
