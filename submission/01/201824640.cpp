#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int signals = 1;

void check(string line) {
	string backup = line;
	signals = 3;

	for (int i = 0; i < line.length(); i++) {
		if (line[i] != line[line.length() - 1 - i]) {
			line.erase(i, 1);
		}
	}

	if (backup.length() - 1 == line.length()) {
		signals = 2;
	}
	else {
		line = backup;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != line[line.length() - 1 - i]) {
				line.erase(line.length() - 1 - i, 1);
			}
		}
	}
	if (backup.length() - 1 == line.length()) {
		signals = 2;
	}
}

int main() {
	string line;
	int max;
	vector<int> v;

	cin >> max;
	for (int i = 0; i < max; i++) {
		cin >> line;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != line[line.length() - 1 - i]) {
				check(line);
				break;
			}
		}
		v.push_back(signals);
		signals = 1;
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}