#include <iostream>
#include <string>
#include <vector>
using namespace std;

string findCode(string& s) {
    int n = s.length();
    vector<vector<string>> memo(n, vector<string>(n, ""));
    
    for(int j=0; j<n; j++) {
        for(int i=j; i>=0; i--) {
            // Base condition
            if(i == j) {
                memo[i][j] = string(1, s[i]);
                continue;
            } 
            
            // Dynamic programing
            string a = memo[i+1][j];
            string b = memo[i][j-1];
            string c = memo[i+1][j-1];
            if(s[i] == s[j]) {
                memo[i][j] = string(1, s[i]) + c + string(1, s[i]);
            } else if(a.length() > b.length()) {
                memo[i][j] = a;
            } else if(a.length() < b.length()) {
                memo[i][j] = b;
            } else if(a.compare(b) < 0) {
                memo[i][j] = a;
            } else {
                memo[i][j] = b;
            }
        }
    }
    
    return memo[0][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    cin >> str;
    cout << findCode(str) << "\n";
}