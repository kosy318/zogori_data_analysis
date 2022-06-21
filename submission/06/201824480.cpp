#include <iostream>
#include <string>
using namespace std;

string code;
string secret[1000][1000];

void findSecretCode(int r, int c) {
	if (code[r] == code[c]) {
		secret[r][c].push_back(code[r]);
		secret[r][c].append(secret[r + 1][c - 1]);
		secret[r][c].push_back(code[c]);
	}
	else if(secret[r][c-1].size() == secret[r + 1][c].size()) {
		if (secret[r][c-1] < secret[r+1][c])
			secret[r][c].append(secret[r][c-1]);
		else
			secret[r][c].append(secret[r+1][c]);
	}
	else {
		if (secret[r][c-1].size() > secret[r+1][c].size())
			secret[r][c].append(secret[r][c-1]);
		else
			secret[r][c].append(secret[r+1][c]);
	}

}

int main() {
	cin >> code;
	for (int i = 0; i < code.size(); i++) {
		secret[i][i] = code[i];
	}
	for (int i = 0; i < code.size() - 1; i++) {
		if (secret[i][i] == secret[i + 1][i + 1]) {
			secret[i][i + 1] = secret[i][i];
			secret[i][i + 1].append(secret[i][i]);
		}
		else
			secret[i][i + 1] = secret[i][i] < secret[i + 1][i + 1] ? 
			secret[i][i] : secret[i + 1][i + 1];
	}

	for (int i = 2; i < code.size(); i++) {
		for (int j = i-2; j >= 0; j--) {
			findSecretCode(j, i);
		}
	}

	cout << secret[0][code.size() - 1];
}