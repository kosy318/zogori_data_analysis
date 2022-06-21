N = int(input())
inp = [input().rstrip() for _ in range(N)]


def check(s, start, end, cnt):
    while start < end:
        if s[start] != s[end]:
            cnt += 1
            if s[start+1] == s[end] and s[start] == s[end-1]:
                cnt1 = check(s, start+1, end, cnt)
                if cnt1 >= 2:
                    return check(s, start, end-1, cnt)
                else:
                    return cnt1

            elif s[start+1] == s[end]:
                start += 1

            elif s[start] == s[end-1]:
                end -= 1

            else:
                return 2

            if cnt >= 2:
                return cnt

        start += 1
        end -= 1

    return cnt


for S in inp:
    answer = check(S, 0, len(S)-1, 0)
    print(answer+1 if answer <= 1 else 3)
