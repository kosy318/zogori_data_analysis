#include <iostream>
#include <vector>
using namespace std;

int main() {
	string code;
	cin >> code;
	int codesize = code.length();

	vector <vector<string>> DP(codesize, (vector<string>(codesize)));

	for (int i = 0; i < codesize; i++) {
		DP[i][i] = code[i];
	}

	for (int k = 1; k < codesize ; k++) {
		for (int i = 0, j = i + k; j < codesize; i++, j++) {
			if (code[i] == code[j]) DP[i][j] = code[i] + DP[i + 1][j - 1] + code[j];
			else {
				if (DP[i +1][j].size() < DP[i][j - 1].size()) 
					DP[i][j] = DP[i][j - 1];
				else if(DP[i + 1][j].size() > DP[i][j - 1].size()) 
					DP[i][j] = DP[i + 1][j];
				else {
					if (DP[i + 1][j] >= DP[i][j - 1]) DP[i][j] = DP[i][j - 1];
					else DP[i][j] = DP[i + 1][j];
				}
			}
		}
	}

	cout << DP[0][codesize - 1] << endl;
}
