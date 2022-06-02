#include <iostream>
#include <string>
using namespace std;

int N;
string s, t;

bool isAvailable(string& S, string& T) {
	int cnt = 0;
	while (!S.empty()) {
		if ((S.back() == T.back()) && (cnt % 2 == 0)) {
			T.pop_back();
			S.pop_back();
			cnt = 0;
			if (T.empty())
				return true;
		}
		else {
			S.pop_back();
			cnt++;
		}
	}
	return false;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		if (isAvailable(s, t))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}