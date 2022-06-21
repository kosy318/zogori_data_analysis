# import sys

def check_palindrome(word):
    front = 0
    back = len(word) - 1
    quasi = False

    while front < back:
        if word[front] == word[back]:
            front += 1
            back -= 1
        else:
            if quasi:
                return 3
            else:
                if front + 1 >= back:
                    break
                else:
                    if word[front + 1] == word[back]:
                        front += 1
                        quasi = True
                    elif word[front] == word[back - 1]:
                        back -= 1
                        quasi = True
                    else:
                        return 3
    if not quasi:
        return 1
    else:
        return 2

def ans():
    # N = int(sys.stdin.readline())
    N = int(input())
    
    for _ in range(N):
        word = input()
        # word = sys.stdin.readline()
        # word = word.strip('\n')
        print(check_palindrome(word))

if __name__ == '__main__':
    ans()
# ans()