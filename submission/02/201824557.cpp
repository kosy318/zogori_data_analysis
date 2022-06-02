#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> indexes;

bool solve(string s,string t) { 
	if (s.length() < t.length()) {
		return false;
	}
	size_t pos = 0;
	int tmp;
	while (s.find(t[0], pos) != string::npos) {
		indexes.clear();
		indexes.push_back(s.find(t[0], pos));
		for (int i = 1; i < t.length(); i++) {
			tmp = s.find(t[i], indexes[indexes.size() - 1]+1);
			if (tmp == string::npos) break;
			else if ((tmp- indexes[indexes.size() - 1])%2 == 1) indexes.push_back(tmp);
			else {
				while (s.find(t[i], tmp + 1) != string::npos) {
					tmp = s.find(t[i], tmp + 1);
					if (tmp != string::npos && (tmp - indexes[indexes.size() - 1]) % 2 == 1) {
						indexes.push_back(tmp);
						break;
					}
				}
			}
		}
		if ((s.length() - indexes[indexes.size() - 1]) % 2 == 1 && t.length() == indexes.size()) {
			return true;
		}
		pos = indexes[0] + 1;
	}
	return false;
	
}

int main() {
	int n;
	cin >> n;
	string s,t;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		if (solve(s, t) == true) cout << "YES" << endl;
		else cout << "NO" << endl;
		indexes.clear();
	}
}