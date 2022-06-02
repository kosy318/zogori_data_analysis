#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	string input;
	string** table;
	cin >> input;

	table = new string * [input.size()];
	for (int i = 0; i < input.size(); i++) {
		table[i] = new string[input.size()];
	}

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input.size() - i; j++) {
			if (j == j + i)
				table[j][j + i] = input[j];
			else {
				if (input[j] != input[j + i]) {
					string left = table[j][j + i - 1];
					string down = table[j + 1][j + i];
					if (left.size() > down.size())
						table[j][j + i] = left;
					else if (left.size() < down.size())
						table[j][j + i] = down;
					else
						table[j][j + i] = (strcmp(left.c_str(), down.c_str()) < 0) ? left : down;
				}
				else {
					if (j - 1 > j + i - 1)
						table[j][j + i] = input[j] + input[j + i];
					else
						table[j][j + i] = input[j] + table[j + 1][j + i - 1] + input[j + i];
				}
			}
		}
	}

	cout << table[0][input.size() - 1] << endl;

	return 0;
}

