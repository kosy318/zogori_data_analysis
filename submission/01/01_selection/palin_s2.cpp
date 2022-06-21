// 참고: https://se-jung-h.tistory.com/m/entry/BOJC-%EB%B0%B1%EC%A4%80-17609-%ED%9A%8C%EB%AC%B8
#include <iostream>
#include <string>

using namespace std;

int isPalin(string s, int check) {
	int start = 0;
	int end = s.size()-1;
	
	while(start<end) {
		if(s[start] == s[end]) {
			start++;
			end--;
		} else {
			if(check==1) {
				if(isPalin(s.substr(start,end-start),2) == 1 || isPalin(s.substr(start+1,end-start),2) == 1) {
					return 2;
				} else {
					return 3;
				}
			} else
				return 3;
		}
	}
	return 1;
}

int main(void) {
	// 동기화 해제
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// 변수 선언
	string s;
	
	int n; cin>>n; // 테스트 케이스
	for(int i=0;i<n;i++) {
		cin>>s;
		cout<<isPalin(s,1)<<"\n";
	}
}