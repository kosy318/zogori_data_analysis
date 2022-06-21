#include <iostream>
#include <string>
#include <vector>
#include <utility>

bool myPred (std::pair<int, std::string> a, std::pair<int, std::string> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;

    std::vector<std::vector<bool>> table(str1.size()+1, std::vector<bool>(str2.size()+1, false));
    std::vector<std::vector<std::pair<int, std::string>>> dp(str1.size()+1, 
        std::vector<std::pair<int, std::string>>(str2.size()+1, {0, ""}));

    for (int i=1; i<str1.size()+1; i++) {
        for (int j=1; j<str2.size()+1; j++) {
            if (str1[i-1] == str2[j-1]) {
                table[i][j] = true;
            }
        }
    }

    std::pair<int, std::string> quasi = {0, ""};

    for (int i=1; i<str1.size()+1; i++) {
        if (table[i][1]) {
            std::string s = std::string(1, str1[i-1]);
            dp[i][1] = {1, s};
            if (dp[i][1].first >= quasi.first) {
                quasi = std::max(quasi, dp[i][1], myPred);
            }
        }
    }

    for (int j=1; j<str2.size()+1; j++) {
        if (table[1][j]) {
            std::string s = std::string(1, str2[j-1]);
            dp[1][j] = {1, s};
            if (dp[1][j].first >= quasi.first) {
                quasi = std::max(quasi, dp[1][j], myPred);
            }
        }
    }

    for (int i=2; i<str1.size()+1; i++) {
        for (int j=2; j<str2.size()+1; j++) {
            if (table[i][j]) {
                dp[i][j] = std::max(
                    std::max(dp[i-2][j-2], dp[i-2][j-1], myPred),
                    std::max(dp[i-1][j-2], dp[i-1][j-1], myPred), myPred);
                dp[i][j].first += 1;
                dp[i][j].second += str1[i-1];

                if (dp[i][j].first >= quasi.first) {
                    quasi = std::max(quasi, dp[i][j], myPred);
                }
            }
        }
    }

    if (quasi.first != 0) {
        std::cout << quasi.second;
    }

    return 0;
}