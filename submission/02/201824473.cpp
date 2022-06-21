#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool backspace(vector<char>, vector<char>);
vector<char> delBackspace(vector<char>);

int main(void) {
	int N;
	cin >> N;
	string s, t;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		vector<char> sVector(s.length()), tVector(t.length());
		copy(s.begin(), s.end(), sVector.begin());
		copy(t.begin(), t.end(), tVector.begin());

		if (backspace(sVector, tVector))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	return 0;
}

bool backspace(vector<char> s, vector<char> t) {
	int space = 0, i;
	vector<char>::iterator iter = t.end()-1;
	for (i = s.size() - 1; i > -1; i--) {
		if (s[i] != *iter) {
			space++;
		}
		else {
			if (space % 2 != 0) {
				space++;
				continue;
			}
			else {
				space = 0;
				if (iter != t.begin()) iter--;
				else break;
			}
		}
	}
	return i > -1;
}
