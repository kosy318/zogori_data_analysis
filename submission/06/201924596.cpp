#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int len = s.length();
    vector< vector<string> > table( len, vector<string>(len) );

    // setting base condition 
    for (int i=0; i<len; ++i) {
        table[i][i] = s[i];
    }

    // filling dp table
    for (int ud=1; ud<len; ++ud) {
        for (int lr=0; lr<len-ud; ++lr) {
            int i = lr;
            int j = lr + ud;

            // case 1. s_0 == s_n
            if (s[i] == s[j]) {
                string s1, s2;
                s1.push_back(s[i]);
                s2.push_back(s[j]);

                if (ud == 1) { // j - i == 1. when calculate with base condition
                    table[i][j] = s1 + s2;
                }
                else {
                    table[i][j] = s1 + table[i + 1][j - 1] + s2;
                }
            }
            // case 2. s_0 != s_n
            else {
                if (ud == 1) { // j - i == 1. when calculate with base condition
                    table[i][j] = std::min(s[i], s[i + 1]);
                }
                else {
                    string s1 = table[i][j - 1];
                    string s2 = table[i + 1][j - 1];
                    string ans = table[i + 1][j];

                    if (ans.length() < s1.length()) {
                        ans = s1;
                    }
                    else if (ans.length() == s1.length()) {
                        if (s1.compare(ans) < 0) {
                            ans = s1;
                        }
                    }

                    if (ans.length() < s2.length()) {
                        ans = s2;
                    }
                    else if (ans.length() == s2.length()) {
                        if (s2.compare(ans) < 0) {
                            ans = s2;
                        }
                    }
                    
                    table[i][j] = ans;
                }
            }
        }
    }

    cout << table[0][len - 1] << endl;

    return 0;
}