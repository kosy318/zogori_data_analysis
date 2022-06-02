#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

#define maxK 10010
#define Testcase 5

using namespace std;

void Flip(int arr[], int left, int right) { // left ~ right 뒤집기 
	stack <int> S;
	
	for (int i = left; i <= right; i++) {
		int k = -1 * arr[i];
		S.push(k);
	}
	
	while (!S.empty()) {
		arr[left++] = S.top();
		S.pop();
	}
}

int Bungeo_ppang(int arr[], int K, int flip_count) {
	// 덜 익은 영역 찾기 
	int left = 1;
	while (left <= K && arr[left] == left) left++; 
	// 덜 익은 영역 찾기 
	int right = K;
	while (right > 0 && arr[right] == right) right--; 
	
	// 모두 잘 굽힌 상태 
	if (left == K+1 || right == 0) return flip_count; 
	// 구울게 하나밖에 없는 상태 
	if (left == right) return flip_count + 1; 
	
	// 덜 익은 영역 중 어디를 뒤집을지 검사 
	for (int i = left; i <= right; i++) {
		if (arr[i] == (left * -1)) {
			Flip(arr, left, i);
			return Bungeo_ppang(arr, K, flip_count + 1);
		}
		if (arr[i] == (right * -1)) {
			Flip(arr, i, right);
			return Bungeo_ppang(arr, K, flip_count + 1);
		}
	}
	
	return 3;
}

int main() {
	fastio;
	
	int K; cin >> K;
	
	int arr[maxK];
	
	for (int t = 0; t < Testcase; t++) {
		for (int i = 1; i <= K; i++)
			cin >> arr[i];
		
		int ans = Bungeo_ppang(arr, K, 0);
		
		if (ans == 1) cout << "one\n";
		if (ans == 2) cout << "two\n";
		if (ans >= 3) cout << "over\n";
	}
}

