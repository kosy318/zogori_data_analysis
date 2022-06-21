import sys

def pair_out(sentence, sota, case):
    if case == 1:
        left = 0
        right = sentence.rfind(sentence[0])
        if right > 0 and right > sentence.rfind(sota[-1]):
            return sentence[0] + sota + sentence[0]
        return sota
    elif case == 2:
        right = 0
        left = sentence.find(sentence[-1])
        if left < len(sentence) - 1 and left < sentence.find(sota[0]):
            return sentence[0] + sota + sentence[0]
        return sota
    else:
        if sentence[0] == sentence[-1]:
            return sentence[0] + sota + sentence[0]
        return sota

def main():
    sentence = sys.stdin.readline().strip()
    n = len(sentence)
    dp = [['' if i!=j else sentence[i] for i in range(n)] for j in range(n)]
    for i in range(1, n):
        for j in range(i-1,-1,-1):
            newsotas = []
            newsotas.append(pair_out(sentence[j:i+1], dp[j+1][i], 2))
            newsotas.append(pair_out(sentence[j:i+1], dp[j][i-1], 1))
            newsotas.append(pair_out(sentence[j:i+1], dp[j + 1][i - 1], 3))
            newsotas.sort(reverse=True)
            newsotas.sort(key=lambda x: len(x))
            dp[j][i] = newsotas[-1]

    print(dp[0][-1])

main()