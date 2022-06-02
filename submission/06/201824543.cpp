#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

bool myPred(std::pair<int, std::string> a, std::pair<int, std::string> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int main() {

    std::string str;
    std::cin >> str;
    

    int len = str.size();
    std::vector<std::vector<std::pair<int, std::string>>> table(len, std::vector<std::pair<int, std::string>>(len, {0, ""}));

    for (int i=0; i<len; i++) {
        table[i][i] = std::make_pair(1, str[i]);
    }

    for (int i=1; i<len; i++) {
        int left = 0;
        int right = i;
        while (left < len-i && right < len) {
            if (str[left] == str[right]) {
                table[left][right] = {table[left+1][right-1].first+2, str[left]+table[left+1][right-1].second+str[right]};
            }
            else {
                table[left][right] = std::max(table[left+1][right], table[left][right-1], myPred);
            }

            left++;
            right++;
        }
    }

    std::cout << table[0][len-1].second;

    return 0;
}