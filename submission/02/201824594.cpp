#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s, t;
int cnt = 0;

bool func(int beg_s, int beg_t) {
	if (beg_t == t.size()) {
		cnt = beg_s;
		return true;
	}

	int beg = beg_s;
	while ((beg = s.find_first_of(t[beg_t], beg + 1)) != string::npos) {
		if (beg == beg_s + 1 || (beg - beg_s + 3) % 2 == 0) {
			if (func(beg, beg_t + 1))
				return true;
		}
	}

	return false;
}

bool func_at_first() {
	int beg = 0, pos = 0;

	while ((beg = s.find_first_of(t[0], pos)) != string::npos) {
		if (func(beg, 1)) {
			if ((s.size() - cnt - 1) % 2 == 0)
				return true;
		}
		pos = beg + 1;
	}

	return false;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> s >> t;
		if (func_at_first())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}