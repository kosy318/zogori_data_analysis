#include <iostream>

using namespace std;

bool checkExist(string s, string t, int start) {
    int n=s.size(), m=t.size(), i=start, j=0;

    while (i < n && j < m) {
        if (s[i] == t[j]) {
            i++;
            j++;
        }
        else i = i + 2;
    }

    if (j == m) return true;
    else return false;
}

void solve() {
    string s, t;
    cin >> s >> t;

    bool ans = false;
    int n=s.size(), m=t.size();
    for (int i=(n-m)%2; i<n-m+1; i+=2) {
        if (s[i] == t[0]) ans = checkExist(s, t, i);
        if (ans == true) break;
    }

    if (ans == true) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}
