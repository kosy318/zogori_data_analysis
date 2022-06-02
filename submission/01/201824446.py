import sys
n = int(sys.stdin.readline().strip())

def palin(word):
    if word == word[::-1]:
        return True
    return False

def isPalin(word):
    left, right = 0,len(word)-1
    if word == word[::-1]:
        return 1
    else:
        while left < right:
            if word[left] != word[right]:# 앞뒤 글자가 다를때 앞덩어리에서 또는 뒷덩어리에서 하나를 제거 한 안쪽 부분이 회문이면 유사회문

                check_left = palin(word[left+1:right+1])
                check_right = palin(word[left:right])

                if check_left or check_right:
                    return 2
                else:
                    return 3
            else:
                left += 1
                right -= 1

for i in range(n):
    inputword=sys.stdin.readline().strip()
    print(isPalin(inputword))


