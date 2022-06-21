#include <iostream>
#include <string>

using namespace std;


bool ispalin(string s) {
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - 1 - i])
			return false;
	}
	return true;
}

bool isqusai(string s) {
	for (int i = 1; i <= s.size(); ++i) {
		string str = s.substr(0, 0 + i - 1) + s.substr(i, s.size() - i);
		if (ispalin(str))
			return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		if (ispalin(s))
			cout << 1 << endl;
		else if (isqusai(s))
			cout << 2 << endl;
		else {
			cout << 3 << endl;
		}
	}

	return 0;
}