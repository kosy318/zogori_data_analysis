#include<bits/stdc++.h>
using namespace std;

int N;
string inString;

vector<string> str;
vector<int> result;

bool Test(deque <char> &dq) {

	while (dq.size() > 1) {
		if (dq.front() != dq.back()) return false;
		else {
			dq.pop_front();
			dq.pop_back();
		}
	}
	return true;
}

void Palindrome(int i) {

	deque <char> dq;
	deque <char> temp;
	copy(str[i].begin(), str[i].end(), back_inserter(dq));

	if(Test(dq)) {
		result.push_back(1);
	}
	else {
		copy(dq.begin(), dq.end(), back_inserter(temp));

		dq.pop_front();
		if (Test(dq)) {
			result.push_back(2);
		}
		else {
			temp.pop_back();
			if (Test(temp)) {
				result.push_back(2);
			}
			else result.push_back(3);
		}
	}
}
void INPUT() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inString;
		str.push_back(inString);
	}
}

void Print() {
	for (auto w : result) {
		cout << w << endl;
	}
}

int main() {
	INPUT();
	for (int i = 0; i < N; i++) {
		Palindrome(i);
	}
	Print();
	return 0;
}