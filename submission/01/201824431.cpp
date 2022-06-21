#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int palindrome(char* str, int mode) { // 회문 판별 함수 
    int len = strlen(str);
    
    // 회문인지 판별 
   	int i;
	for (i = 0; i < len/2; i++) {
   		if (str[i] != str[len-i-1]) {
   			break;
		}
	}
	if (i >= len/2) {
		return 1; // 회문이면, 1을 반환
	}
	if (mode == 1) {
		return 3;
	}
	
	// 유사회문인지 판별 
	for (i = 0; i < len; i++) {
		char str_temp[100000] = "";
		for (int j = 0; j < len-1; j++) {
			if (j < i) {
				str_temp[j] = str[j];
			} else if (j >= i) {
				str_temp[j] = str[j+1];
			}
		}
		if (palindrome(str_temp, 1) == 1) {
			return 2; // 2를 반환 
		}
	}
	
	// 그외의 경우, 3을 반환 
	return 3;
}

int main(void) {
    int n;
    scanf(" %d", &n);

    for(int i = 0; i < n; i++) {
        char temp[100000];
        scanf(" %s", temp);
        printf("%d\n", palindrome(temp, 0));
    }
	
	return 0;
}
