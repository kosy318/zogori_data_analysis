#include <bits/stdc++.h>
using namespace std;

int N;
vector<char> input;
vector<vector<string>> code;

void read() {
	vector<string> temp;
	string str;
	cin >> str;

	input = vector<char>(str.begin(), str.end());
	N = input.size();
	for(int i = 0; i < N; i++) { temp.push_back("")	 ; }
	for(int i = 0; i < N; i++) { code.push_back(temp); }
	for(int i = 0; i < N; i++) { code[i][i] = input[i]	 ; }
}

string palin(int i, int j) {
	if (code[i][j] != "") { return code[i][j]; }

	string a, b, result;
	if (input[i] == input[j]) {
		if (i + 1 == j) {
			code[i][j].push_back(input[i]);
			code[i][j].push_back(input[i]);
			return code[i][j];
		}
		else {
			a = input[i] + palin(i+1, j-1) + input[i];
			b = palin(i, j-1);
		}
	}
	else {
		a = palin(i, j-1);
		b = palin(i+1, j);
	}

	if		(a.size() > b.size()) { result = a; }
	else if (a.size() < b.size()) { result = b; }
	else {
		if (a > b) { result = b; }
		else	   { result = a; }
	}
	return code[i][j] = result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	cout << palin(0, N-1) << "\n";
	return 0;
}
