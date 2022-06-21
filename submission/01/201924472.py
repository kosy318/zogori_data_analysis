n = int(input())
PALINDROME = 1
QUASI_PALINDROME = 2
NOTHING = 3


def is_palindrome(s, f, b):
    org = s[f:b+1]
    reverse = org[::-1]
    return org == reverse


for _ in range(n):
    string = input()
    front = 0
    back = len(string)-1
    state = PALINDROME

    while front <= back:
        if string[front] != string[back]:
            if is_palindrome(string, front+1, back) or is_palindrome(string, front, back-1):
                state = QUASI_PALINDROME
                break
            else:
                state = NOTHING
                break

        front += 1
        back -= 1

    print(state)
