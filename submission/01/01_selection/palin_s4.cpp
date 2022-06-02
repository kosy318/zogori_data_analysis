#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r])   return false;
        l++;
        r--;
    }
    return true;
}
bool isQuasiPalindrome(string s) {
    int l = 1;
    int r = s.size() - 1;
    int cntMismatch = 0;
    while (l < r) {
        if (s[l] != s[r])   cntMismatch++;
        l++;
        r--;
    }
    if (cntMismatch == 0)   return true;

    int i = 1, t = s.size();
    while (i < (t / 2)) {
        if (s[i] != s[t-i])     cntMismatch--;
        if (s[i-1] != s[t-i])   cntMismatch++;

        if (cntMismatch == 0)   return true;
        i++;
    }
    if (t % 2 == 0) i++;
    while (i < t) {
        if (s[i] != s[t-1-i])       cntMismatch--;
        if (s[i-1] != s[t-1-i])     cntMismatch++;

        if (cntMismatch == 0)   return true;
        i++;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, res = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (isPalindrome(s))               res = 1;
        else if (isQuasiPalindrome(s))     res = 2;
        else                               res = 3;
        cout << res << '\n';
    }
    return 0;
}