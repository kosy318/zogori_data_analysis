#include <bits/stdc++.h>
using namespace std;
bool isBackspace(string& s, string& t);

int main() {
    int num;
    cin >> num;
    for(int i=0; i<num; i++){
        string s, t;
        cin >> s >> t;
        if(isBackspace(s, t)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
bool isBackspace(string& s, string& t){
    int n = s.length();
    int m = t.length();
    int dp[n];
    dp[n-1] = dp[n-2] = -1;
    if(s[n-1] == t[m-1]){
        dp[n-1] = 0;
        if(m>=2 && s[n-2] == t[m-2]){ //t의길이가 1이면 m-2는 -1이므로 m>=2 라는 조건 추가 
            dp[n-2] = 1;
        }
    }
    for(int i=2; i<n; i++){
        if(s[n-i-1] == t[m-dp[n-i]-2]){
            if(dp[n-i] == -1 && i%2 == 1){
                dp[n-i-1] = dp[n-i+1];
            }
            else{
                dp[n-i-1] = dp[n-i] + 1;
            }
        }
        else{
            dp[n-i-1] = dp[n-i+1];
        }
        if(dp[n-i-1] == m-1){
            return true;
        }
    }
    return false;
}

