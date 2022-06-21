#include <bits/stdc++.h>
using namespace std;

int k, T = 5;

void outcome(int cnt) {
	switch(cnt) {
		case 1: {
			cout << "one" << "\n";
			break;
		}
		case 2: {
			cout << "two" << "\n";
			break;
		}
		default: {
			cout << "over" << "\n";
			break;
		}
	}
}

void flip(deque<int>& Fish, int b, int e) {
	deque<int> ch;

	for(int i = 0; i < b; i++) {
		ch.push_back(Fish.at(i));
	}
	for(int i = e; i >= b; i--) {
		ch.push_back(-Fish.at(i));
	}
	for(int i = e + 1; i < Fish.size(); i++) {
		ch.push_back(Fish.at(i));
	}

	Fish = ch;
}

void operating(deque<int> Fish, int b, int e, int cnt) {
	if (cnt >= 3) {
		outcome(cnt);
		return;
	}

	for(int i = 0; i < Fish.size(); i++) {
		if (Fish.at(i) == b)  {
			Fish.pop_front();
			i--;
			b++;
		}
		else { break; }
	}

	for(int i = Fish.size() - 1; i >= 0; i--) {
		if (Fish.at(i) == e)  {
			Fish.pop_back();
			e--;
		}
		else { break; }
	}

	auto it1 = find(Fish.begin(), Fish.end(), -b);
	auto it2 = find(Fish.begin(), Fish.end(), -e);

	if (!Fish.size()) {
		outcome(cnt);
		return;
	}

	if (it1 != Fish.end()) {
		flip(Fish, 0, it1 - Fish.begin());
		cnt++;
	}
	else if (it2 != Fish.end()) {
		flip(Fish, it2 - Fish.begin(), Fish.size() - 1);
		cnt++;
	}
	else {
		cnt = 3;
	}

	operating(Fish, b, e, cnt);
}

void read() {
	cin >> k;

	while(T) {
		deque<int> Fish;

		for(int i = 0; i < k; i++) {
			int t;
			cin >> t;
			Fish.push_back(t);
		}

		operating(Fish, 1, k, 0);
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
