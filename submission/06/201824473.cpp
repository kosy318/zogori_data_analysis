#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	vector<vector<string>> palin;
	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		vector<string> temp;
		for (int j = 0; j < len; j++) {
			temp.push_back("");
		}
		palin.push_back(temp);
	}
	for (int i = 0; i < len; i++) {
		palin[i][i] = str[i];
	}

	for (int i = len - 2; i >= 0; i--) {
		for (int j = i + 1; j < len; j++) {
			string choice;
			choice = palin[i + 1][j];
			if (str[i] == str[j]) {
				string tmp = str[i] + palin[i + 1][j - 1] + str[i];
				if (choice.length() < palin[i][j - 1].length()) {
					choice = palin[i][j - 1];
				}
				else if (choice.length() == palin[i][j - 1].length()) {
					if (choice > palin[i][j - 1])
						choice = palin[i][j - 1];
				}
				if (choice.length() < tmp.length()) {
					choice = tmp;
				}
				else if (choice.length() == tmp.length()) {
					if (choice > tmp) {
						choice = tmp;
					}
				}
			}
			else {
				if (choice.length() < palin[i][j - 1].length()) {
					choice = palin[i][j - 1];
				}
				else if (choice.length() == palin[i][j - 1].length()) {
					if (choice > palin[i][j - 1])
						choice = palin[i][j - 1];
				}
			}
			palin[i][j] = choice;
		}
	}



	cout << palin[0][len - 1] << endl;
	/*for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << palin[i][j] << "\t";
		}
		cout << "\n";
	}*/

	return 0;
}
