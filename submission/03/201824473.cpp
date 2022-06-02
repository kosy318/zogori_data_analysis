#include <iostream>
#include <vector>

using namespace std;

void flipAndMinus(vector<int>&, int, int);
bool checkArray(vector<int>);
void fish(vector<int>);
int countMinus(vector<int>);

int main(void) {
	int k;
	cin >> k;

	for (int i = 0; i < 5; i++) {
		vector<int> arr;
		for (int j = 0; j < k; j++) {
			int in;
			cin >> in;
			arr.push_back(in);
		}
		fish(arr);


		//for (int l : arr) {
		//	cout << l << " ";
		//}
		//cout << endl;
	}
}

void flipAndMinus(vector<int>& arr, int left, int right) {
	int sub = (right - left) / 2;
	for (int i = 0; i <= sub; i++) {
		int temp = -arr[left + i];
		arr[left + i] = -arr[right - i];
		arr[right - i] = temp;
	}
}

bool checkArray(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (abs(arr[i]) != i + 1) return false;
	}
	return true;
}

int countMinus(vector<int> arr) {
	int count = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (-arr[i] == i + 1) count++;
	}
	return count;
}

void fish(vector<int> arr) {
	int leftCnt = 0, rightCnt = 0;
	int l = 0, r = 0;
	vector<int> cpyL;
	vector<int> cpyR;

	for (int i = 0; i < arr.size(); i++) {
		cpyL.push_back(arr[i]);
		cpyR.push_back(arr[i]);
	}
	//cout << "left" << endl;
	for (l = 0; l < 3; l++) {
		if (checkArray(cpyL)) {
			l += countMinus(cpyL);
			break;
		}
		int left, right;
		for (int i = 0; i < cpyL.size(); i++) {
			if (i + 1 != abs(cpyL[i])) {
				left = i;
				break;
			}

		}
		for (int i = 0; i < cpyL.size(); i++) {
			if (left + 1 == abs(cpyL[i])) {
				right = i;
				break;
			}

		}

		flipAndMinus(cpyL, left, right);
		//cout << endl;
		//for (int l : cpyL) {
		//	cout << l << " ";
		//}
		//cout << endl;
	}
	//cout << "right" << endl;
	for (r = 0; r < 3; r++) {
		if (checkArray(cpyR)) {
			r += countMinus(cpyR);
			break;
		}
		int left, right;
		for (int i = cpyR.size() - 1; i >= 0; i--) {
			if (i + 1 != abs(cpyR[i])) {
				right = i;
				break;
			}
		}

		for (int i = cpyR.size() - 1; i >= 0; i--) {
			if (right + 1 == abs(cpyR[i])) {
				left = i;
				break;
			}
		}
		flipAndMinus(cpyR, left, right);
		//cout << endl;
		//for (int l : cpyR) {
		//	cout << l << " ";
		//}
		//cout << endl;
	}

	int count = min(l, r);
	if (count == 1) cout << "one" << endl;
	else if (count == 2) cout << "two" << endl;
	else cout << "over" << endl;
}
