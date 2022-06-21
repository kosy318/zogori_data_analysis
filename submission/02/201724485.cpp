#include <bits/stdc++.h>
using namespace std;

int T;
string s, t;
vector<int> dis;
vector<bool> result;

void get_result() {
	for(int i = 0; i < dis.size()-1; i++) {
		if ((dis.at(i+1) - dis.at(i)) % 2 == 0) {
			result.push_back(false);
			return;
		}
	}
	result.push_back(true);
}

void operating(vector<char> in, vector<char> fi, int n, int m) {
	if (dis.size() == fi.size()) {
		dis.push_back(s.size());
		get_result();
		dis.pop_back();
		return;
	}

	for(int i = n; i < in.size(); i++) {
		if (in.at(i) != fi.at(m)) { continue; }
		dis.push_back(i);
		operating(in, fi, i + 1, m+1);
		dis.pop_back();
	}
}

void outcome() {
	if (count(result.begin(), result.end(), true)) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
}

void read() {
	cin >> T;
	while(T) {
		cin >> s >> t;
		vector<char> in(s.begin(), s.end());
		vector<char> fi(t.begin(), t.end());

		operating(in, fi, 0, 0);
		outcome();
		dis.clear();
		result.clear();
		T--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	return 0;
}
