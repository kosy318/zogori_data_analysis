def decending(s):
    if len(s) == 1:
        return True

    p = s[0]
    for m in range(1, len(s)):
        if p + 1 != s[m]:
            return False
        p = s[m]

    return True

def find_region(indexes):
    jump = []
    if decending(indexes):
        return 1, indexes

    count = 1
    previous = indexes[0]
    for idx in range(1, len(indexes)):
        if previous + 1 != indexes[idx]:
            jump.append(previous)
            jump.append(indexes[idx])
            count += 1
        previous = indexes[idx]

    return count, jump


def solution():
    answer_list = []
    N = int(input())
    for _ in range(5):
        k = []
        t = [0 for _ in range(N+1)]
        t[1:] = list(map(int, input().split()))
        check = True
        wrong = []
        for idx in range(1,N+1):
            if idx != t[idx]:
                if check:
                    min_index = max_index = idx
                    min_value = max_value = abs(t[idx])
                    check = False
                wrong.append(idx)
                if min_value > abs(t[idx]):
                    min_value = abs(t[idx])
                    min_index = idx
                if max_value < abs(t[idx]):
                    max_value = abs(t[idx])
                    max_index = idx

        if find_region(wrong)[0] > 2:
            answer_list.append('over')
            continue
        elif find_region(wrong)[0] == 2:
            if decending(t[wrong[0]:find_region(wrong)[1][0] + 1]) and decending(
                    t[find_region(wrong)[1][1]:wrong[-1] + 1]):
                answer_list.append('two')
                continue
            else:
                answer_list.append('over')
                continue
        else:
            if decending(t[wrong[0]:wrong[-1] + 1]):
                answer_list.append('one')
                continue
            else:
                nn = [wrong[0], max_index, min_index, wrong[-1]]
                my_set = set(nn)
                my_list = sorted(list(my_set))
                for i in range(len(my_list)-1):
                    for j in range(i+1, len(my_list)):
                        if len(t[my_list[i]:my_list[j]+1]) != 0:
                            think = list(map(lambda x: x * -1, t[my_list[j]:my_list[i] - 1:-1]))
                            t1 = t.copy()
                            t1[my_list[i]:my_list[j] + 1] = think
                            wrong2 = [idx for idx, value in enumerate(t1) if idx != value]
                            if len(t1) == N + 1 and find_region(wrong2)[0] == 1 and decending(
                                    t1[wrong2[0]:wrong2[-1] + 1]):
                                k.append(2)
                            else:
                                k.append(3)

                if len(k) !=0 and min(k) == 2:
                    answer_list.append('two')
                else:
                    answer_list.append('over')

    for value in answer_list:
        print(value)

solution()