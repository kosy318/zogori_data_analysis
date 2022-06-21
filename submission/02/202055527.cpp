#include <bits/stdc++.h>

using namespace std;

string comstr(string mstr, string sstr) {
	int diff = mstr.length() - sstr.length();
	int i = 0, j = 0;
	if (diff < 0)  return "NO";
	if (diff % 2 == 1) i++;
	while (true) {
		if (sstr[j] == NULL) return "YES";
		if (mstr[i] == NULL) return "NO";

		if (sstr[j] != mstr[i]) i += 2;
		else { i++; j++; }

	}
}


void getinput() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string mstr;
		string sstr;
		cin >> mstr >> sstr;
		cout << comstr(mstr, sstr) << endl;
	}
}



int main() {
	getinput();
}