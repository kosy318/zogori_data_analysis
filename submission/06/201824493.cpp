#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string input;
	cin >> input;
	int size = input.length();
	vector<vector<string>> dp(size, vector<string>(size, ""));
	for (int i = 0; i < size; i++) {
		dp[i][i] = input[i];
	}
	int m=0, re = size - 1;
	int x1=0, y1=1;
	while (re != 0) {
		int x = x1, y = y1;
		for (int i = 0; i < re; i++) {
			if (input[x] != input[y]) {
				if (dp[x][y-1].length()>dp[x+1][y].length()) {
					dp[x][y] = dp[x][y - 1];
				}
				else if(dp[x][y - 1].length() < dp[x + 1][y].length()){
					dp[x][y] = dp[x+1][y];
				}
				else {
					if (dp[x][y - 1].compare(dp[x + 1][y]) <= 0) {
						dp[x][y] = dp[x][y - 1];
					}
					else dp[x][y] = dp[x+1][y];
				}
			}
			else {
				string sx = input.substr(x, 1);
				dp[x][y] = sx + dp[x + 1][y - 1] + sx;
			}
			if (m < dp[x][y].length()) m = dp[x][y].length();
			x++; y++;
		}
		y1++; re--;
	}
	cout << dp[0][size-1];
	return 0;
}