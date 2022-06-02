#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;
vector<int> indexes;
vector<int> save;
vector<int> check;

bool successCheck();
bool absSuccessCheck();
void flip(int start, int end);
void print();
bool doubleCheck;
int solve() {	
	int cnt = 0;
	int minus = 0;
	int k;
	int small,pos;
	while (true) {
		if (cnt > 2) return 3;
		small = 10000;
		pos = 0;
		if (successCheck() == true) {
			for (int i = 0; i < N; i++) {
				if (arr[i] != i + 1) {
					minus++;
					indexes.push_back(i);
				}
			}
			switch (minus) {
			case 0:
				return cnt;
			case 1:
				return cnt + 1;
			case 2:
				if (indexes[0] + 1 == indexes[1]) return 1 + cnt;
				else return 2 + cnt;
			default:
				return 3;
			}
		}
		else if (doubleCheck == false) {
			for (int j = 0; j < N; j++) {
				if (min(arr[j],small) == arr[j]) {
					small = arr[j];
					pos = j;
				}
			}
			flip(pos, abs(small) - 1);
			cnt++;
		}
		else {
			k = check.size() + 1;
			if (abs(arr[k - 1]) == k) {
				check.push_back(k);
			}
			else {
				for (int j = k; j < N; j++) {
					if (abs(arr[j]) == abs(k)) {
						flip(k - 1, j);
						cnt++;
					}
				}
			}
		}

	}
}

void print() {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


bool successCheck() {
	for (int i = 0; i < N; i++) {
		if (abs(arr[i]) != i + 1) return false;
	}
	return true;
}
bool absSuccessCheck() {
	for (int i = 0; i < N; i++) {
		if (arr[i] != i + 1) return false;
	}
	return true;
}

void flip(int start, int end) {
	int tmp;
	for (int i = 0; i < (end - start) / 2 + 1; i++) {
		tmp = arr[start + i] * (-1);
		arr[start + i] = arr[end - i] * (-1);
		arr[end - i] = tmp;
	}
}

int main() {
	int input;
	int result;
	cin >> N;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			arr.push_back(input);
		}
		save = arr;
		result = solve();
		if (result > 2) {
			doubleCheck = true;
			indexes.clear();
			check.clear();
			arr = save;
			result = solve();
		}
		switch (result) {
		case 1:
			cout << "one" << endl;
			break;
		case 2:
			cout << "two" << endl;
			break;
		default:
			cout << "over" << endl;
		}
		arr.clear();
		indexes.clear();
		check.clear();
		save.clear();
		doubleCheck = false;
	}
}