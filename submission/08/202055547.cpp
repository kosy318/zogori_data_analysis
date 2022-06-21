#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int dx[4] = {-2, -1, -2, -1};
int dy[4] = {-2, -2, -1, -1};

int dp[100][100];
string LCQS[100][100];

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int max_len = 0;
    string ans = "";

    for (int i=0; i<s1.size(); i++) {
        for (int j=0; j<s2.size(); j++) {
            dp[i][j] = 0;
            if (s1[i] == s2[j]) {
                dp[i][j] = 1;

                string str;
                for (int k=0; k<4; k++) {
                    int ni = i + dy[k];
                    int nj = j + dx[k];
                    if (ni < 0 || nj < 0) continue;

                    if (dp[ni][nj] != 0) {
                        if (dp[i][j] <= dp[ni][nj]) {
                            dp[i][j] = dp[ni][nj] + 1;
                            str = LCQS[ni][nj];
                        }
                        else if (dp[i][j] == dp[ni][nj] + 1) {
                            string tmp = LCQS[ni][nj];
                            if (str.compare(tmp) > 0) {
                                str = tmp;
                            }
                        }
                    }
                }
                str.push_back(s1[i]);
                LCQS[i][j] = str;

                if (dp[i][j] > max_len) {
                    ans = str;
                    max_len = dp[i][j];
                }
                else if (dp[i][j] == max_len) {
                    if (ans.compare(str) > 0) {
                        ans = str;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

