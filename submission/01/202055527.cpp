#include <bits/stdc++.h>

using namespace std;


int palindrome(string sen, int start, int end, int num_diff) {
	if (start >= end) return num_diff;
	while (sen[start] == sen[end]) {
		if (start >= end) return num_diff;
		start++; end--;
	}
	if (num_diff == 1) 
		if  ((palindrome(sen, start + 1, end, num_diff + 1) - 1) == 1 || (palindrome(sen, start, end - 1, num_diff + 1) - 1) == 1) return 2;
		
	return 3;
}

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string sent;
		cin >> sent;
		cout << palindrome(sent, 0, sent.length() - 1, 1) << endl;
	}
	
	return 0;

}