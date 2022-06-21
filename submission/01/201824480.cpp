#include <iostream>
#include <string>
using namespace std;

int N;

bool isPalin(string& str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != str[str.size() - 1 - i])
			return false;
	}
	return true;
}

bool isQpalin(string& str) {
	for (int idx = 0; idx < str.size(); idx++) {
		string newstr(str);
		newstr.erase(idx, 1);
		if (isPalin(newstr))
			return true;
	}
	return false;
}

int main() {
	cin >> N;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (isPalin(str))
			cout << 1 << endl;
		else if (isQpalin(str)) {
			cout << 2 << endl;
		}
		else {
			cout << 3 << endl;
		}
	}
}