#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

#define maxK 10010
#define Testcase 5

using namespace std;

void Flip(int arr[], int left, int right) { // left ~ right µÚÁý±â 
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
	// ´ú ÀÍÀº ¿µ¿ª Ã£±â 
	int left = 1;
	while (left <= K && arr[left] == left) left++; 
	// ´ú ÀÍÀº ¿µ¿ª Ã£±â 
	int right = K;
	while (right > 0 && arr[right] == right) right--; 
	
	// ¸ðµÎ Àß ±ÁÈù »óÅÂ 
	if (left == K+1 || right == 0) return flip_count; 
	// ±¸¿ï°Ô ÇÏ³ª¹Û¿¡ ¾ø´Â »óÅÂ 
	if (left == right) return flip_count + 1; 
	
	// ´ú ÀÍÀº ¿µ¿ª Áß ¾îµð¸¦ µÚÁýÀ»Áö °Ë»ç 
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