#include <iostream>
#include <string>

using namespace std;

int Palindrome(string word) {
    int left = 0, right = word.length() - 1;

    while (left <= right) {
        if (word[left] == word[right]) {
            ++left, --right;
        }
        else {

            int l = left + 1, r = right;
            bool l_pass = true;

            while (l <= r) {
                if (word[l] != word[r]) {
                    l_pass = false;
                    break;
                }
                ++l, --r;
            }

            if (l_pass) {
                return 2;
            }

            l = left, r = right - 1;
            bool r_pass = true;

            while (l <= r) {
                if (word[l] != word[r]) {
                    r_pass = false;
                    break;
                }
                ++l, --r;
            }

            if (r_pass) {
                return 2;
            }

            return 3;
        }
    }

    return 1;
}

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        string word;
        cin >> word;

        cout << Palindrome(word) << "\n";
    }

    return 0;
}
