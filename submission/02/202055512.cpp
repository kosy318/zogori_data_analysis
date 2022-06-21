#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s, t;
	while (n--) {
		cin >> s >> t;
		int ssize = s.size(), tsize = t.size();
		if (ssize == tsize) {
			if (s == t) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
		else if (ssize < tsize)
			cout << "NO" << '\n';
		else {
			int tidx = tsize - 1;
			bool flag[10001] = { false, };
			string ss = "";
			for (int i = ssize - 1; i >= 0; i--) {
				if (tidx < 0) 
					break;
				if (t[tidx] == s[i]) {
					if (tidx == tsize - 1) {
						flag[i] = true;
						tidx--;
						continue;
					}
					flag[i] = true;
					flag[i + 1] = true;
					tidx--;

				}
				else {
					if (i >= 1) {
						s[i] = '*';
						s[i - 1] = '*';
					}
					i--;
				}
			}
			for (int i = 0; i < ssize; i++) {
				if (flag[i] && s[i] != '*') ss += s[i];
			}
			if (ss == t) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}