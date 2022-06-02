#include <iostream>
#include <string>
#include <algorithm>

bool test(const std::string& sStr, const std::string& tStr) {

    for (int i=0; i<sStr.size() - tStr.size()+1; i++) {
        bool previousExist = false;
        int tIdx = 0;
        int sIdx = i;
        for (; sIdx<sStr.size() && tIdx < tStr.size(); sIdx++) {
            if (tStr[tIdx] != sStr[sIdx]) {
                if (previousExist && sIdx+1 < sStr.size()) {
                    sIdx++;
                }
            }
            else {
                previousExist = true;
                tIdx++;
            }
        }

        if (tIdx >= tStr.size()) {
            if ((sStr.size() - sIdx)%2==0) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int testCase;
    std::cin >> testCase;

    for (int tc=0; tc<testCase; tc++) {
        std::string s;
        std::string t;

        std::cin >> s >> t;

        if (test(s, t)) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }

    return 0;
}