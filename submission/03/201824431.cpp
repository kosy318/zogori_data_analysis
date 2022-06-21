#include <iostream>
#include <vector>

using namespace std;

int n;

void flipArray(vector<int> &arr, int s, int e) {
	for (int i = s, j = e; i <= j; i++, j--) {
		int temp = arr[i] * -1;
		arr[i] = arr[j] * -1;
		arr[j] = temp;
	}
}

bool flip1(vector<int> arr) {
	int cnt = 0;
	if (arr[0] != 1) {
		cnt++;
	}
	for (int i = 0; i < n-1; i++) {
		if (arr[i] + 1 != arr[i+1]) {
			cnt++;
		}
	}
	if (arr[n-1] != n) {
		cnt++;
	}
	
	if (cnt <= 2) {
		return true;
	}
	
	return false;
}

bool flip2(vector<int> arr) {
	// 3. A와 독립된 경우
	// 3-1. A와 독립되어 하나만 뒤집힌 경우
	int s = -1, e = n-1;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0 && arr[i] * -1 == i+1) {
			s = i;
			break;
		}
	}
	if (s != -1) {
		flipArray(arr, s, s);
		if (flip1(arr)) {
			return true;
		}
		flipArray(arr, s, s);
	}
	
	// 3-2. 그 외의 경우 
	s = 0, e = n-1;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] + 1 != arr[i+1]) {
			if (s == 0) {
				s = i+1;
			}
			else {
				e = i;
				break;
			}
		}
	}
	
	flipArray(arr, s, e);
	if (flip1(arr)) {
		return true;
	}
	flipArray(arr, s, e);
	
	// 1. A구간 안에 쏙 들어가지는 경우  
	s = 0, e = n-1;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] < 0 && arr[i+1] > 0) {
			s = i+1;
		}
		else if (s != 0 && arr[i] > 0 && arr[i+1] < 0) {
			e = i;
			break;
		}
	}
	
	flipArray(arr, s, e);
	if (flip1(arr)) {
		return true;
	}
	flipArray(arr, s, e);
		
	// 2. A와 일부만 겹치는 경우
	s = 0, e = n-1;
	vector<int> c;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] > 0 && arr[i] != i+1) {
			c.push_back(i);
		}
	}
	
	if (!c.empty()) {
		s = c.front();
		e = c.back();
	}
	
	
	flipArray(arr, s, e);
	if (flip1(arr)) {
		return true;
	}
	flipArray(arr, s, e);
	
	s = 0, e = n-1;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] < 0 && arr[i+1] < 0 && arr[i] + 1 != arr[i+1]) {
			s = i+1;
		}
		else if (arr[i] > 0 && arr[i+1] == i+2 && arr[i] + 1 != arr[i+1]) {
			e = i;
			break;
		}
	}
	
	flipArray(arr, s, e);
	if (flip1(arr)) {
		return true;
	}
	flipArray(arr, s, e);
	
	s = 0, e = n-1;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] == i+1 && arr[i+1] > 0 && arr[i] + 1 != arr[i+1]) {
			s = i+1;
		}
		else if (arr[i] < 0 && arr[i+1] < 0 && arr[i] + 1 != arr[i+1]) {
			e = i;
			break;
		}
	}
	
	flipArray(arr, s, e);
	if (flip1(arr)) {
		return true;
	}
	flipArray(arr, s, e);
	
	return false;
}

int fish(vector<int> arr) {
	if (flip1(arr)) {
		return 1;
	}
	
	if (flip2(arr)) {
		return 2;
	}
	
	return 3;
}

int main(void) {
    cin >> n;
    
    for (int i = 0; i < 5; i++) {
    	vector<int> flip(n, 0);
    	
    	for (int j = 0; j < n; j++) {
    		cin >> flip[j];
		}
		
		switch (fish(flip)) {
			case 1:
				cout << "one\n";
				break;
			case 2:
				cout << "two\n";
				break;
			default:
				cout << "over\n";
				break;
		}
	}
	
	return 0;
}
