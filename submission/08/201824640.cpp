#include <bits/stdc++.h>
using namespace std;

int find(vector<vector<int>> v, int x, int y) {
	vector<int> e(4, 0);
	int ex;

	if (x < 1 and y < 1) {
		return 0;
	}
	if (x - 1 >= 0 and y - 1 >= 0) {
		ex = v[x - 1][y - 1];
		e[0] = ex;
	}
	if (x - 1 >= 0 and y - 2 >= 0) {
		ex = v[x - 1][y - 2];
		e[1] = ex;
	}
	if (x - 2 >= 0 and y - 1 >= 0) {
		ex = v[x - 2][y - 1];
		e[2] = ex;
	}
	if (x - 2 >= 0 and y - 2 >= 0) {
		ex = v[x - 2][y - 2];
		e[3] = ex;
	}

	sort(e.begin(), e.end());
	return e[3];
}

void print(vector<vector<int>> v, int maxs, int x, int y, string a, string &com) {
	if (maxs == 0) {
		return;
	}
	else if (x - 1 >= 0 and y - 1 >= 0 and v[x - 1][y - 1] == maxs - 1) {
		print(v, maxs - 1, x - 1, y - 1, a, com);
		com += a[x];
	}
	else if (x - 1 >= 0 and y - 2 >= 0 and v[x - 1][y - 2] == maxs - 1) {
		print(v, maxs - 1, x - 1, y - 2, a, com);
		com += a[x];
	}
	else if (x - 2 >= 0 and y - 1 >= 0 and v[x - 2][y - 1] == maxs - 1) {
		print(v, maxs - 1, x - 2, y - 1, a, com);
		com += a[x];
	}
	else if (x - 2 >= 0 and y - 2 >= 0 and v[x - 2][y - 2] == maxs - 1) {
		print(v, maxs - 1, x - 2, y - 2, a, com);
		com += a[x];
	}
	else if (maxs == 1) {
		com += a[x];
		return;
	}
}

int main(void) {
	vector<string> ans;
	string a, b;
	cin >> a >> b;
	vector<vector<int>> v(a.size(), vector<int>(b.size(), 0));

	int maxs = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (a[i] == b[j]) {
				v[i][j] += find(v,i,j) + 1;
				if (v[i][j] > maxs) {
					maxs = v[i][j];
				}
			}
		}
	}

	string com = "";
	for (int i = v.size()-1; i >= 0; i--) {
		for (int j = v[i].size()-1 ; j >= 0; j--) {
			if (v[i][j] == maxs) {
				print(v, maxs, i, j, a, com);
			}
			if (com != "") {
				ans.push_back(com);
			}
			com = "";
		}
	}
	sort(ans.begin(), ans.end());

	cout << ans[0] << endl;
	return 0;
}