#include <iostream>
#include <string>
using namespace std;

bool isDelete(string& s, string& t) {
    int slen = s.length();
    int tlen = t.length();
    if(slen < tlen) {
        return false;
    }
    
    int i=0, j=0;
    while(i < slen && j < tlen) {
        if(s[i] == t[j]) {
            i++;
            j++;
        } else {
            i += 2;
        }
    }
    if((j == tlen) && ((slen-i) % 2) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    string s, t;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    while(n--) {
        cin >> s >> t;
        if(isDelete(s, t)) {
            cout << "YES\n"; 
        } else if(isDelete(s.erase(0, 1), t)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}