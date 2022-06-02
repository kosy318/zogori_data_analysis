#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

int N;
deque<int> fishbread;

bool flippedOnce(deque<int> fb) {
	deque<int> temp;
	while (!fb.empty()) {
		if (fb.back() == fb.size())
			fb.pop_back();
		else {
			temp.push_back(-fb.back());
			fb.pop_back();
		}
	}
	int gap = temp.front();
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] - i != gap)
			return false;
	}
	return true;
}

bool isCase1(deque<int> fb) {
	deque<int> temp;
	for (int i = 0; i < fb.size(); i++) {
		if (fb[i] != i + 1)
			temp.push_back(i);
	}
	for (int i = temp[0]; i < temp[temp.size() - 1] + 1; i++)
		fb[i] = -fb[i];
	reverse(fb.begin() + temp[0], fb.begin() + temp[temp.size() - 1] + 1);
	if (flippedOnce(fb))
		return true;
	else
		return false;
}

bool isCase2(deque<int> fb) {
	deque<int> temp;
	for (int i = 0; i < fb.size(); i++) {
		if (fb[i] != i + 1)
			temp.push_back(i);
	}
	for (int i = 0; i < fb.size() - 1; i++) {
		if (fb[i] > fb[i + 1] && fb[i] < 0 && fb[i + 1] < 0) {
			reverse(fb.begin() + i + 1, fb.begin() + temp[temp.size()-1] + 1);
			for (int j = i + 1; j < temp[temp.size() - 1] + 1; j++)
				fb[j] = -fb[j];
			if(flippedOnce(fb))
				return true;
			reverse(fb.begin() + i + 1, fb.begin() + temp[temp.size() - 1] + 1);
			for (int j = i + 1; j < temp[temp.size() - 1] + 1; j++)
				fb[j] = -fb[j];
			reverse(fb.begin() + temp[0], fb.begin() + i + 1);
			for (int j = temp[0]; j < i + 1; j++)
				fb[j] = -fb[j];
			if (flippedOnce(fb))
				return true;
			return false;
		}
	}
	return false;
}

bool isCase3(deque<int> fb) {
	deque<int> temp;
	for (int i = 0; i < fb.size(); i++) {
		if (fb[i] != i + 1)
			temp.push_back(i);
	}
	int gap = fb[temp[0]] - temp[0];
	int index = 0;
	for (int i = temp[0]; i < fb.size(); i++) {
		if (fb[i] - i != gap) {
			index = i;
			break;
		}
	}
	for (int i = temp[0]; i < index; i++) {
		fb[i] = -fb[i];
	}
	reverse(fb.begin() + temp[0], fb.begin() + index);
	if (flippedOnce(fb))
		return true;
	else
		return false;
}

bool flippedTwice(deque<int> fb) {
	if (isCase1(fb))
		return true;
	else if (isCase2(fb))
		return true;
	else if (isCase3(fb))
		return true;
	return false;
}

int main() {
	cin >> N;
	for (int i = 0; i < 5; i++) {
		fishbread.clear();
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			fishbread.push_back(temp);
		}
		if (flippedOnce(fishbread)) {
			cout << "one" << endl;
		}
		else if (flippedTwice(fishbread))
			cout << "two" << endl;
		else
			cout << "over" << endl;
	}
}
