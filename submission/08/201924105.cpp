#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string& a, string& b) {
    if(a.length() > b.length()) {
        return true;
    } else if(a.length() == b.length()) {
        return a.compare(b) <= 0;
    }
    return false;
}

string findLCQS(string &s1, string &s2) {
    string LCQS = "";
    int n = s1.length();
    int m = s2.length();
    // store all CQS by n*m
    vector<vector<string>> memo(n, vector<string>(m, ""));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(s1[i] == s2[j]) {
                vector<string> candidates;
                if(i >= 2 && j >= 2)
                    candidates.push_back(memo[i-2][j-2]);
                if(i >= 2 && j >= 1)
                    candidates.push_back(memo[i-2][j-1]);
                if(i >= 1 && j >= 2)
                    candidates.push_back(memo[i-1][j-2]);
                if(i >= 1 && j >= 1)
                    candidates.push_back(memo[i-1][j-1]);
                sort(candidates.begin(), candidates.end(), cmp);
                
                memo[i][j] = (candidates.size() > 0 ? candidates[0] : "") + string(1, s1[i]);
                LCQS = cmp(memo[i][j], LCQS) ? memo[i][j] : LCQS;
            } 
        }
    }
    return LCQS;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s1, s2;
    cin >> s1 >> s2;
    cout << findLCQS(s1, s2) << "\n";
}