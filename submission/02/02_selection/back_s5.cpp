#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin>>t;
	string s1;
	string s2;
	
	int p1;
	int p2;
	int size;
	int cnt;
	for(int i=0;i<t;i++) {
		cin>>s1;
		cin>>s2;
		p1=s1.size()-1;
		p2=s2.size()-1;
		cnt=0;
		
		while(1) {
			if(p2<0) { // s1 문자열을 다 돈 경우
				cout<<"YES\n";
				break;
			} else if(p1<0) { // s2 문자열을 다 돈 경우
				cout<<"NO\n";
				break;
			}
			
			if(s1[p1]==s2[p2] && cnt%2==0) { // 두 문자가 같으면서 cnt가 짝수인 경우
				p1--;
				p2--;
				cnt=0;
			} else { // 두 문자열이 다르거나, cnt가 홀수인 경우
				p1--;
				cnt++;
			}
		}
	}
}