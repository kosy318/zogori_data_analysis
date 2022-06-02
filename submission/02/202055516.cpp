#include <bits/stdc++.h>

using namespace std;

int N, b, f;
string s, t;
vector<string> before, after;
vector<bool> answer;
queue<pair<int, int>> q;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> s >> t;
        before.push_back(s);
        after.push_back(t);
    }
}


void check() {
    for(int m=b; m<s.length(); m++) {
        if(s[m]==t[f]&&(m-b)%2==0) {
            q.push({m+1, f+1});
        }
    }
}


void canMake() {
    if(s.length() < t.length()) { answer.push_back(false); return; }

    for(int k=0; k<s.length(); k++) {
        if(s[k]==t[0]) q.push({k+1, 1}); // t의 첫 글자와 일치하는 위치
    }

    while(!q.empty()) {
        b = q.front().first;
        f = q.front().second;
        q.pop();

        if(f!=t.length()) check();
        else if((s.length()-b)%2==1) continue;
        else { answer.push_back(true); return; }
    }
    answer.push_back(false);
}


void solve() {
    for(int j=0; j<N; j++) {
        s = before[j]; t = after[j];
        q = queue<pair<int,int>>();
        canMake();
   }
}


void output() {
    for(auto a : answer) {
        if(a) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}


int main() {
    input();
    solve();
    output();
    return 0;

}
