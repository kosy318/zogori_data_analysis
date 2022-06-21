#include <bits/stdc++.h>
using namespace std;

const int MAX_L = 100;
string s, t;
string optimalQuasi = "";
string cache[MAX_L+1][MAX_L+1];

bool compare(const string& a, const string& b) {
    return (a.size() != b.size()) ? a.size() > b.size() : a < b;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s >> t;
}
void compute() {
    fill(&cache[0][0], &cache[MAX_L][MAX_L], "");
    for (int si = 0; si < s.size(); si++) {
        for (int ti = 0; ti < t.size(); ti++) {
            if (s[si] == t[ti]) {
                cache[si][ti] = s[si];
                for (int sj = si - 2; sj < si; sj++) {
                    for (int tj = ti - 2; tj < ti; tj++) {
                        if (sj >= 0 && tj >= 0)
                            cache[si][ti] = min(cache[si][ti], cache[sj][tj] + s[si], compare);
                    }
                optimalQuasi = min(optimalQuasi, cache[si][ti], compare);
                }
            }
        }
    }
}
void output() {
    cout << optimalQuasi << '\n';
}

int main() {
    input();
    compute();
    output();
}