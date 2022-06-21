#include <bits/stdc++.h>
using namespace std;
string s, l, r, dp[1001][1001];

void init(int len) {
    for(int i=0;i<len;i++) dp[i][i] = s[i];
    for(int i=1;i<len;i++)
        if(s[i]==s[i-1]) dp[i][i-1] = string{s[i]} + s[i];
        else dp[i][i-1] = min(s[i-1], s[i]);
}

void memoize(int len) {
    for(int k=2;k<len;k++)
    for(int i=k;i<len;i++) {
        string &target = dp[i][i-k];
        tie(l, r) = {dp[i-1][i-k], dp[i][i-k+1]};

        if(s[i-k] != s[i])
            if(l.size()==r.size()) target = min(l, r);
            else target = l.size() > r.size() ? l : r;
        else target = s[i] + dp[i-1][i-k+1] + s[i];
    }
}

int main() {
    cin >> s;
    int len = s.length();

    init(len);
    memoize(len);

    cout << dp[len-1][0];
}