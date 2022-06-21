#include <iostream>
#include <string>

using namespace std;

string input, dp[1000][1000];

void pallindrome(int y,int x) {
	if (input[y] == input[x]) {
		dp[y][x] = dp[y + 1][x - 1];
		dp[y][x] = dp[y][x].insert(0, 1, input[x]) + input[x];
	}
	else {
		if (dp[y + 1][x].length() > dp[y][x - 1].length()) dp[y][x] = dp[y + 1][x];
		else if (dp[y + 1][x].length() == dp[y][x - 1].length() && dp[y + 1][x] < dp[y][x - 1]) dp[y][x] = dp[y + 1][x];
		else dp[y][x] = dp[y][x - 1];
	}
}

void solve() {
	for (int i = input.length() - 2; i >= 0; i--) {
		for (int j = i; j < input.length(); j++) {
			if (dp[i][j].length() == 0) pallindrome(i,j);
		}
	}
}

int main() {
	cin >> input;

	for (int i = 0; i < input.length(); i++) dp[i][i] = input[i];

	solve();
	cout << dp[0][input.length() - 1] << endl;
}