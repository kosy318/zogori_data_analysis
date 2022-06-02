#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
	string str;
	cin >> str;

	int N = str.length();

	vector<string> temp(N, "");
	vector<vector<string>> table(N, temp);

	string check;


	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			int j = i + k;
			if (j >= N) { continue; }

			if (j - i == 0) { table[i][i] = str[i]; }
			else if (j - i == 1) {
				if (str[i] == str[j]) {	// char끼리 더해서 string 함수에 넣어주면 Error, string 변수 만들어 push_back 이용해야 됨
					string s;
					s.push_back(str[i]);
					s.push_back(str[j]);
					table[i][j] = s;
				}	
				else { table[i][j] = (str[i] <= str[j]) ? str[i] : str[j]; }
			}
			else {
				if (str[i] == str[j]) { table[i][j] = str[i] + table[i+1][j-1] + str[i]; }
				else {
					if (table[i][j-1].length() == table[i+1][j].length()) {
						table[i][j] = (table[i][j-1] <= table[i+1][j]) ? table[i][j-1] : table[i+1][j];
					}
					else {
						table[i][j] = (table[i][j - 1].length() >= table[i + 1][j].length()) ? table[i][j - 1] : table[i + 1][j];
					}
				}
			}

			check = table[i][j];
		}
	}

	cout << table[0][N-1] << endl;

}