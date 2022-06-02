#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

void init() {
    cin >> n;
    while(n--) {
        string s1, s2, ans = "";
        cin >> s1 >> s2;
        reverse(s2.begin(), s2.end());
        int idx = 0;
        bool flag = false;
        while(!s1.empty()) {
            char s = s1.back();
            s1.pop_back();
            if(flag) flag = false;
            else if(s == s2[idx]) {
                ans += s;
                idx++;
            }
            else flag = true;
        }
        if(ans == s2) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}																		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}