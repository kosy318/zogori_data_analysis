#include <iostream>
#include <string>

using namespace std;
string dp[1000][1000];

string compare(string a, string b) {
    if (a.length() > b.length()) return a;
    else if (a.length() < b.length()) return b;
    else if (a < b) return a;
    else return b;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // length 1
    for (int i=0; i<n; i++) {
        dp[i][i] = s[i];
    }

    // length 2
    for (int i=0; i<n-1; i++) {
        if (s[i] == s[i+1]) dp[i][i+1] = s.substr(i, 2);
        else dp[i][i+1] = compare(s.substr(i, 1), s.substr(i+1, 1));
    }

    // dp[a][b] = max(dp[a][b-1], dp[a+1][b], if(s[a]==s[b]) s[a]+dp[a+1][b-1]+s[b] )
    int range = 3;
    while (range <= n) {
        for (int l = 0; l <= n-range; l++) {
            int r = l + range - 1;
            dp[l][r] = compare(dp[l+1][r], dp[l][r-1]);
            if (s[l] == s[r])
                dp[l][r] = compare(dp[l][r], s.substr(l, 1) + dp[l+1][r-1] + s.substr(r, 1));
        }
        range++;
    }

    cout << dp[0][n-1] << endl;
}
