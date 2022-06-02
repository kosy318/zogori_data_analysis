#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 1e32
#define X first
#define Y second
using namespace std;
typedef long long ll;
ll DP[2][31][31];
bool visit[2][31][31];
vector<ll> num;
vector<string> p, in;
string s;
 
ll dfs(int s, int e, int x) {
    if(s == e) return num[s];
    if(visit[x][s][e]) return DP[x][s][e];
    visit[x][s][e] = true;
    if(x) DP[x][s][e] = INF;
    else DP[x][s][e] = -INF;
    for(int i=s; i<e; i++) {
        if(p[i] == "+") {
            if(x) DP[x][s][e] = min(DP[x][s][e], dfs(s, i, 1) + dfs(i+1, e, 1));
            else DP[x][s][e] = max(DP[x][s][e], dfs(s, i, 0) + dfs(i+1, e, 0));
        }
        if(p[i] == "-") {
            if(x) DP[x][s][e] = min(DP[x][s][e], dfs(s, i, 1) - dfs(i+1, e, 0));
            else DP[x][s][e] = max(DP[x][s][e], dfs(s, i, 0) - dfs(i+1, e, 1));
        }
        if(p[i] == "*") {
            if(x) {
                DP[x][s][e] = min(DP[x][s][e], dfs(s, i, 1) * dfs(i+1, e, 0));
                DP[x][s][e] = min(DP[x][s][e], dfs(s, i, 0) * dfs(i+1, e, 1));
            }
            else {
                DP[x][s][e] = max(DP[x][s][e], dfs(s, i, 0) * dfs(i+1, e, 0));
                DP[x][s][e] = max(DP[x][s][e], dfs(s, i, 1) * dfs(i+1, e, 1));
            }
        }
    }
    return DP[x][s][e];
}


void init() {
    memset(visit, false, sizeof(visit));
    while (!cin.eof()) { 
        cin >> s;
        in.push_back(s);
    }
    for(int i=0; i<in.size(); i++) {
        if(i%2) p.push_back(in[i]);
        else num.push_back(stol(in[i]));
    }
    int n = num.size()-1;
    dfs(0, n, 0);
    cout << DP[0][0][n] << '\n';
}


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}


