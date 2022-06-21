#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0;

void reversearr(int arr[], int l, int r);
vector<string> ans;

int forwardflip(int arr[]) {
	int cnt=0, change = 0;
	int l=0, r = 0;
	int* arr2 = new int[n + 1];
	copy(arr, arr + n + 1, arr2);
	while (true) {
		for (int i = 1; i < n + 1; i++) {
			if (i != abs(arr2[i])) {
				l = i;
				for (int j = l; j < n + 1; j++) {
					if (i == abs(arr2[j])) {
						r = j;
						break;
					}
				}
				reversearr(arr2, l, r);
				cnt++;
			}
		}
		change++;
		if (cnt != change) break;
	}
	for (int i = 1; i < n + 1; i++) {
		if (i == -arr2[i]) cnt++;
	}
	delete[] arr2;
	return cnt;
}

int backwardflip(int arr[]) {
	int cnt=0, change = 0;
	int l=0, r = 0;
	int* arr2 = new int[n + 1];
	copy(arr, arr + n + 1, arr2);
	while (true) {
		for (int i = n ; i > 0; i--) {
			if (i != abs(arr2[i])) {
				r = i;
				for (int j = r; j >0; j--) {
					if (i == abs(arr2[j])) {
						l = j;
						break;
					}
				}
				reversearr(arr2, l, r);
				cnt++;
			}
		}
		change++;
		if (cnt != change) break;
	}
	for (int i = 1; i < n + 1; i++) {
		if (i == -arr2[i]) cnt++;
	}
	delete[] arr2;
	return cnt;
}

void reversearr(int arr[], int l, int r) {
	int leng = r - l;
	for (int i = 0; i < ((leng) / 2)+1; i++) {
		if (r == l) {
			arr[r] = -arr[r];
		}
		else {
			int temp = arr[l];
			arr[l] = -arr[r];
			arr[r] = -temp;
			l++;
			r--;
		}
	}
}

void cknum() {
	int* arr = new int[n + 1];
	for (int i = 1; i < n+1; i++) {
		cin >> arr[i];
	}
	int fflipcnt = forwardflip(arr);
	int bflipcnt = backwardflip(arr);
	int result = min(fflipcnt, bflipcnt);
	if (result == 1)  ans.push_back("one");
	else if (result == 2) ans.push_back("two");
	else ans.push_back("over");
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 5; i++) {
		cknum();
	}
	for (int i = 0; i < 5; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}

