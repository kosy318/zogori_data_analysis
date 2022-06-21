#include <bits/stdc++.h>
using namespace std;

int T;

void operating(string str) {
	int cnt = 0;
	vector<char> v(str.begin(), str.end());
	vector<char> sub1;
	vector<char> sub2;

	for(int i = 0; i < v.size() / 2; i++) {
		if (v.at(i) != v.at(v.size() - i - 1)) {
			sub2 = v;
			v.erase(v.begin() + i);
			sub1 = v;
			v = sub2;
			v.erase(v.begin() + v.size() - i - 1);
			sub2 = v;
			cnt++;
			break;
		}
	}

	if (cnt) {
		vector<char> sub11;
		vector<char> sub12;
		vector<char> sub21;
		vector<char> sub22;
		for(int i = 0; i < sub1.size() / 2; i++) {
			sub11.push_back(sub1.at(i));
			sub12.push_back(sub1.at(sub1.size() - i - 1));
		}
		for(int i = 0; i < sub2.size() / 2; i++) {
			sub21.push_back(sub2.at(i));
			sub22.push_back(sub2.at(sub2.size() - i - 1));
		}

		if (sub11 == sub12 || sub21 == sub22) {
			cout << 2 << "\n";
		}
		else {
			cout << 3 << "\n";
		}

	}
	else {
		cout << 1 << "\n";
	}
}

void read() {
	cin >> T;

	while(T) {
		string str;
		cin >> str;
		operating(str);
		T--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	return 0;
}
