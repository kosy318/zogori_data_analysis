#include <bits/stdc++.h>
using namespace std;
int n, len;

void init() {
	cin >> n;
    while(n--) {
        string s, rs;
        cin >> s;
        rs = s, len = s.size()-1;
        reverse(rs.begin(), rs.end());
        if(s == rs) cout << 1 << '\n';
        else {
            string str1, str2, str3, str4;
            for(int i=0; i<=len; i++) {
                if(s[i] == s[len-i]) continue;
                str1 = s.substr(0, i) + s.substr(i+1, len-i);
                str2 = s.substr(0, len-i) + s.substr(len-i+1, i);
                break;
            }
            str3 = str1, str4 = str2;
            reverse(str3.begin(), str3.end());
            reverse(str4.begin(), str4.end());
            if(str1 == str3 || str2 == str4) cout << 2 << '\n';
            else cout << 3 << '\n';
        }
    }
}																		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}