#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s, int n) {
    for(int i=0, j=n-1; i<j; i++, j--) {
        if(s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

bool isPseudoPalindrome(string s, int n) {
    string r = s;
    for(int i=0, j=n-1; i<j; i++, j--) {
        if(s[i] != s[j]) {
            s.erase(i, 1);
            r.erase(j, 1);
            break;
        }
    }
    return isPalindrome(s, n-1) || isPalindrome(r, n-1);
}

int classifyPalindrome(string s) {
    int n = s.length();
    if(isPalindrome(s, n)) {
        return 1;
    } else if(isPseudoPalindrome(s, n)) {
        return 2;
    } else {
        return 3;
    }
}

int main() {
    int t;
    string s;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--) {
        cin >> s;
        cout << classifyPalindrome(s) << "\n";
    }
    return 0;
}