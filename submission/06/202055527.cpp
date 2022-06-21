#include <bits/stdc++.h>

using namespace std;


string S;
int sz;


void setTable(int i, int j, vector<vector<string>>& Ts) {
	string a = Ts[i + 1][j];
	string b = Ts[i][j - 1];
	if (S[i] == S[j]) {
		Ts[i][j] = S[i] + Ts[i + 1][j - 1] + S[j];
	}
	else {
		if (a.size() == b.size()) {
			if (strcmp(a.c_str(), b.c_str()) >= 0) {
				Ts[i][j] = b;
			}
			else {
				Ts[i][j] = a;
			}
		}
		else if (a.size() > b.size()) Ts[i][j] = a;
		else Ts[i][j] = b;
	}
}


int main() {
	cin >> S;
	sz = S.size();
	vector<vector<string>> Ts(sz, vector<string>(sz));
	Ts[0][0] = S[0];
	for (int i = 1; i < sz; i++) {
		Ts[i][i-1] = "";
		Ts[i][i] = S[i];
	}

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz - i - 1; j++) {
			setTable(j, j + i + 1, Ts);
		}
	}






	cout << Ts[0][sz - 1];

}