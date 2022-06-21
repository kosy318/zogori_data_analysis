#include <bits/stdc++.h>
using namespace std;

bool isParlindrome(string str) {
    for(int i=0;i<str.size();i++)
        if(str[i] != str[str.size()-i-1]) 
            return false;
    return true;
}

int solve(string str) {
    if(isParlindrome(str)) return 1;

    bool isQuasi = false;
    for(int i=0;i<str.size();i++) {
        string tmp = str;
        tmp.erase(tmp.begin() + i);
        if(isParlindrome(tmp)) isQuasi = true;
    }
    return isQuasi ? 2 : 3;
}

int main() {
    int N; string str;
    cin >> N;
    while(cin >> str) cout << solve(str) << '\n';
}