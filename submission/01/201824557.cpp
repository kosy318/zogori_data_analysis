#include <iostream>
#include <string>


using namespace std;

void solve2(string temp);

void solve(string temp) { 
	bool cnt = false;
	int left = 0;
	int right = 0;
	int length = temp.length();
	for (int i = 0; i < length / 2; i++) {
		if (temp[i + left] == temp[length - 1 - i - right]) continue;
		else {
			if (temp[i] == temp[length - 2 - i] && right == 0 && left == 0 && cnt == false) {
				cnt = true;
				right++;
				continue;
			}
			if (temp[i + 1] == temp[length - 1 - i] && right == 0 && left == 0 && cnt == false) {
				cnt = true;
				left++;
				continue;
			}
			else {
				solve2(temp);
				return;
			}
		}
	}
	if (cnt == false) cout << "1" << endl;
	else cout << "2" << endl;
}
void solve2(string temp) {
	bool cnt = false;
	int left = 0;
	int right = 0;
	int length = temp.length();
	for (int i = 0; i < length / 2; i++) {
		if (temp[i + left] == temp[length - 1 - i - right]) continue;
		else {
			if (temp[i + 1] == temp[length - 1 - i] && right == 0 && left == 0 && cnt == false) {
				cnt = true;
				left++;
				continue;
			}
			if (temp[i] == temp[length - 2 - i] && right == 0 && left == 0 && cnt == false) {
				cnt = true;
				right++;
				continue;
			}
			else {
				cout << "3" << endl;
				return;
			}
		}
	}
	if (cnt == false) cout << "1" << endl;
	else cout << "2" << endl;
}


int main() {
	int n;
	cin >> n;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		solve(temp);
	}
	
}