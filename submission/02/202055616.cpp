#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> s;
vector<string> t;
vector<string> result;

void INPUT() {
	string S, T;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		s.push_back(S);
		t.push_back(T);
	}
}

bool odd(int x) { 
	if (x % 2 == 1) return true;
	else return false;
}

int test(int i, int start, int index , bool isodd) { 

	if (index == t[i].size()) return -2;

	while (true) {
		int x = s[i].find(t[i][index], start);
		if (x == string::npos) {
			return -1;
		}
		else if (odd(x) != isodd) return x;
		else {
			start = x + 1;
		}
	}
}
void BackSpace(int i) {
	int index = 0, start = 0,res;
	int odd_index = test(i, start, index, false);
	int even_index = test(i, start, index, true);
	
	vector<int> Case;
	Case.push_back(odd_index);
	Case.push_back(even_index);

	for (int j = 0; j < 2; j++) {
		int x = Case[j];
		index = 1;
		start = x + 1;
		while (x != -1) {

			res = test(i, start, index, odd(x));

			if (res == -1) {
				break;
			}
			else if (res == -2) {
				if (odd(x) != odd(s[i].size())) {
					result.push_back("YES");
					return;
				}
				break;
			}
			else {
				start = res + 1;
				index++;
				x = res;
			}
		}
	}
	result.push_back("NO");
}
void print() {
	for (auto w : result) {
		cout << w << endl;
	}
}
int main() {
	INPUT();
	for (int i = 0; i < N; i++) {
		if (s[i].size() < t[i].size() || s[i].find(t[i][0]) == string::npos) result.push_back("NO");
		else BackSpace(i);
	}
	print();
	return 0;
}