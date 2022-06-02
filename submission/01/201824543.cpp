#include <iostream>
#include <string>

bool test(const std::string& strCopy, int l, int r) {
    while (l < r) {
        if (strCopy[l] != strCopy[r]) {
            return false;
        }
        l++;
        r--;
    }

    return true;
}

int main() {
    int testCase;
    std::cin >> testCase;

    for (int t=0; t<testCase; t++) {
        std::string str;
        std::cin >> str;

        int left = 0;
        int right = str.size()-1;
        int count = 1;

        while (left < right) {
            if (str[left] != str[right]) {
                count++;
                if (!test(str, left+1, right) && !test(str, left, right-1)) {
                    count++;
                }

                break;
            }
            left++;
            right--;
        }

        std::cout << count << "\n";
    }

    return 0;
}