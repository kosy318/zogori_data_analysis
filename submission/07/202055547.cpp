#include <iostream>

using namespace std;

int n;
int inp[100][3];
int dp[1096][2];

int main() {
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> inp[i][0] >> inp[i][1] >> inp[i][2];

    for (int i=0; i<n; i++) {
        int start = inp[i][0];
        int end = inp[i][1];
        int price = inp[i][2];
        if (dp[end][0] < price) {
            dp[end][0] = max(dp[end][0], price);
            dp[end][1] = end - start + 1;
        }
        else if (dp[end][0] == price) {
            dp[end][1] = min(dp[end][1], end - start + 1);
        }
    }

    for (int start=1; start<=1095; start++) {
        if (dp[start-1][0] > dp[start][0]) {
            dp[start][0] = dp[start-1][0];
            dp[start][1] = dp[start-1][1];
        }

        for (int i=0; i<n; i++) {
            if (inp[i][0] == start) {
                int end = inp[i][1];
                int total = dp[start-1][0] + inp[i][2] - 10;
                if (dp[end][0] < total) {
                    dp[end][0] = total;
                    dp[end][1] = dp[start-1][1] + end - start + 1;
                }
                else if (dp[end][0] == total) {
                    dp[end][1] = min(dp[end][1], dp[start-1][1] + end - start + 1);
                }
            }
        }
    }

    cout << dp[1095][0] << " " << dp[1095][1];
}
