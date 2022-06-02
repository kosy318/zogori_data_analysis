def check(a, b):
    l_a, l_b = len(a), len(b)
    if l_a > l_b: return a
    elif l_a < l_b: return b
    if a >= b: return b
    return a


word = input()
word_len = len(word)

res2 = [["" for _ in  range(word_len)] for __ in range(word_len)]
"""res[i][j] 는 i번째 원소부터 j번째 원소까지의 최고 회문을 의미."""

for j, w in enumerate(word):
    for i in range(j,-1,-1):
        if i==j:
            res2[i][j] = w
        else:
            my_find = word[i:j].find(w)
            if my_find != -1:
                if my_find+i == j-1:
                    my_find_word = w*2
                else:
                    my_find_word = w+res2[i+my_find+1][j-1]+w
                res2[i][j] = check(my_find_word, res2[i][j-1])
            else:
                res2[i][j] = check(res2[i][j-1], w)

# for i, re in enumerate(res2):
#     for j, r in enumerate(re):
#         print(f"({i},{j}):{r}", end=" ")
#     print()
print(res2[0][-1])
