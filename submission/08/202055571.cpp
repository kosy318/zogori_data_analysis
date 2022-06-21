#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct index {
	int i;
	int j;
};

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	vector<vector<int>> dp(s1.length() + 2, vector<int>(s2.length() + 2, 0));

	for (int i = 2; i < s1.length()+2; i++) {
		for (int j = 2; j < s2.length()+2; j++) {
			if (s1[i - 2] == s2[j - 2]) dp[i][j] = max({ dp[i - 1][j - 1], dp[i - 2][j - 1], dp[i - 1][j - 2], dp[i - 2][j - 2] }) + 1;
			else dp[i][j] = 0;
		}
	}

	/*
	for (int i = 0; i < s1.length() + 2; i++) {
		for (int j = 0; j < s2.length() + 2; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/

	int m=0;
	for (int i = 2; i < s1.length() + 2; i++) {
		if (*max_element(dp[i].begin(), dp[i].end()) > m) m = *max_element(dp[i].begin(), dp[i].end());
	}

	vector<index> idxs;
	index idx;
	for (int i = 2; i < s1.length() + 2; i++) {
		if (find(dp[i].begin(), dp[i].end(), m) != dp[i].end()) {
			idx.i = i;
			idx.j = find(dp[i].begin(), dp[i].end(), m) - dp[i].begin();
			idxs.push_back(idx);
		}
	}

	vector<string> strs;
	string str;
	for (auto it = idxs.begin(); it != idxs.end(); it++) {
		int i = it->i;
		int j = it->j;
		int cnt = m;
		while (cnt > 0) {
			str.push_back(s1[i-2]);
			cnt--;
			if (dp[i - 1][j - 1] == cnt) { i = i - 1; j = j - 1; }
			else if (dp[i - 1][j - 2] == cnt) { i = i - 1; j = j - 2; }
			else if (dp[i - 2][j - 1] == cnt) { i = i - 2; j = j - 1; }
			else if (dp[i - 2][j - 2] == cnt) { i = i - 2; j = j - 2; }
		}
		reverse(str.begin(), str.end());
		strs.push_back(str);
		str.clear();
	}

	sort(strs.begin(), strs.end());
	cout << strs.front() << endl;
}