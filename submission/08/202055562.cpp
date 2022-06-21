#include <iostream>
#include <vector>
using namespace std;

int main() {

    string String_i, String_j;

    cin >> String_i >> String_j;
    string ans = "";
    vector <vector<string> > dp(String_i.size(), vector<string> (String_j.size()));

    for (int i = 0; i < String_i.size(); i++) {
        for (int j = 0; j < String_j.size(); j++) {
            if (String_i[i] == String_j[j]) {
                if (i == 0 || j == 0) {
                    for (int temp_i = 0; temp_i < 2; temp_i++) {
                        for (int temp_j = 0; temp_j < 2; temp_j++) {
                            if (i + temp_i < String_i.size() && j + temp_j < String_i.size()) {
                                dp[i + temp_i][j + temp_j] = String_i[i];
                            }
                        }
                    }
                }
                else {
                    for (int temp_i = 0; temp_i < 2; temp_i++) {
                        for (int temp_j = 0; temp_j < 2; temp_j++) {
                            if (i + temp_i < String_i.size() && j + temp_j < String_j.size()) {
                                if (dp[i + temp_i][j + temp_j].size() <= dp[i - 1][j - 1].size() + 1) {
                                    dp[i + temp_i][j + temp_j] = dp[i - 1][j - 1] + String_i[i];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            if (dp[i][j].size() > ans.size()) ans = dp[i][j];
            if (dp[i][j].size() == ans.size()) {
                if (dp[i][j] < ans) ans = dp[i][j];
            }
        }
    }

    cout << ans;
    return 0;
}
