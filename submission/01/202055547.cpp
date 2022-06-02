#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    for (int i=0; i<s.size()/2; i++) {
        if (s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;

    for (int l=0,r=s.size()-1; l<r; l++, r--) {
        if (s[l] != s[r]) {
            bool left = isPalindrome(s.substr(l+1, s.size()-2*l-1));
            bool right = isPalindrome(s.substr(l, s.size()-2*l-1));
            if (left || right) cout << 2 << endl;
            else cout << 3 << endl;
            return;
        }
    }
    cout << 1 << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}
