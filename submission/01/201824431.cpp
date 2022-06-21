#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int palindrome(char* str, int mode) { // ȸ�� �Ǻ� �Լ� 
    int len = strlen(str);
    
    // ȸ������ �Ǻ� 
   	int i;
	for (i = 0; i < len/2; i++) {
   		if (str[i] != str[len-i-1]) {
   			break;
		}
	}
	if (i >= len/2) {
		return 1; // ȸ���̸�, 1�� ��ȯ
	}
	if (mode == 1) {
		return 3;
	}
	
	// ����ȸ������ �Ǻ� 
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
			return 2; // 2�� ��ȯ 
		}
	}
	
	// �׿��� ���, 3�� ��ȯ 
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
