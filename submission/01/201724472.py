def ispalin(sentence):
    if sentence == sentence[::-1]:
        return True
    else:
        return False


N = int(input())
answer = []
for k in range(N):
    palin = input()
    if ispalin(palin):
        answer.append(1)
    else:
        for i in range(len(palin)):
            if ispalin(palin[:i] + palin[i + 1:]):
                answer.append(2)
                break
        if k + 1 != len(answer):
            answer.append(3)

for i in range(len(answer)):
    if i == len(answer) - 1:
        print(answer[i], end='')
    else:
        print(answer[i])
