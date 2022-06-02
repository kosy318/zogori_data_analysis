#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isQuasiPlaindrome(vector<char>);

int Palindrome(vector<char> str, int palin=1) {
	while (!str.empty()) {
		if (!(str.front() == str.back())) {
			if (isQuasiPlaindrome(str)) {
				palin = 2;
				break;
			}
			else {
				palin = 3;
				break;
			}
		}

		str.erase(str.begin());
		if (!str.empty()) str.pop_back();
	}
	return palin;
}

bool isQuasiPlaindrome(vector<char> str) {
	int palin1 = 0;
	int palin2 = 0;
	vector<char> cpyStr = str;


	str.erase(str.begin());
	while (!str.empty()) {
		if (!(str.front() == str.back())) {
			palin1++;
		}

		str.erase(str.begin());
		if (!str.empty()) str.pop_back();
	}


	cpyStr.pop_back();
	while (!cpyStr.empty()) {
		if (!(cpyStr.front() == cpyStr.back())) {
			palin2++;
		}

		cpyStr.erase(cpyStr.begin());
		if (!cpyStr.empty()) cpyStr.pop_back();
	}
	return palin1 == 0 || palin2 == 0;
}

int main(void) {
	int N;
	string inputString;


	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inputString;
		vector<char> inputVector(inputString.length());
		copy(inputString.begin(), inputString.end(), inputVector.begin());

		cout << Palindrome(inputVector) << endl;
	}
	return 0;

}
