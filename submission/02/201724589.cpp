#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<string> sq;
queue<string> tq;
queue<bool> result;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		sq.push(str1);
		tq.push(str2);
	}
	int count = 0;
	string sstr = sq.front();
	string tstr = tq.front();
	string::iterator siter = sstr.end();
	siter--;
	string::iterator titer = tstr.end();
	titer--;
	bool checkbool = false;
	bool endbool = false;
	while (true) {
		if (*siter == *titer && !(count % 2)) {
			if (titer == tstr.begin()) {
				checkbool = true;
				endbool = true;
			}
			else titer--;
			count = 0;
		}
		else count++;
		if (siter == sstr.begin()) {
			endbool = true;
		}
		if (endbool) {
			result.push(checkbool);
			endbool = false;
			checkbool = false;
			sq.pop();
			tq.pop();
			if (sq.empty() || tq.empty()) break;
			sstr = sq.front();
			tstr = tq.front();
			siter = sstr.end();
			titer = tstr.end();
			titer--;
			count = 0;
		}
		siter--;
	}
	while (true) {
		if (result.empty()) break;
		if (result.front()) cout << "YES" << endl;
		else cout << "NO" << endl;
		result.pop();
	}
	return 0;
}