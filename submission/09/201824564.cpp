#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 32;

typedef long long ll;

struct box { ll max, min; };

int N;
ll num[maxN];
char opr[maxN];
box dp[maxN][maxN];

vector <ll> V;

void Input() {
    fastio;
    string str; getline(cin, str);
    stringstream in(str);

    int i = 1;
    in >> num[i];
    dp[1][1] = {num[1], num[1]};

    while (in >> opr[i]) {
        in >> num[i+1];
        dp[i+1][i+1] = {num[i+1], num[i+1]};
        i++;
    }
    N = i;
}

ll simple_calc(ll a, char oper, ll b) {
    ll ret = a;
    if (oper == '+') ret += b;
    if (oper == '*') ret *= b;
    if (oper == '-') ret -= b;
    return ret;
}

void get_min_max(int l, int a, int b, int r) {
    V.push_back(simple_calc(dp[l][a].max, opr[a], dp[b][r].max));
    if (a - l > 1) {
        V.push_back(simple_calc(dp[l][a].min, opr[a], dp[b][r].max));
        if (r - b > 1) {
            V.push_back(simple_calc(dp[l][a].min, opr[a], dp[b][r].min));
            V.push_back(simple_calc(dp[l][a].max, opr[a], dp[b][r].min));
        }
    }
    else if (r - b > 1)
        V.push_back(simple_calc(dp[l][a].max, opr[a], dp[b][r].min));
}

box complex_calc(int y, int x) {
    box ret;
    for (int i = y; i < x; i++) {
        get_min_max(y, i, i+1, x);
        sort(V.begin(), V.end());
    }
    ret = {V.back(), V.front()};
    V.clear();
    return ret;
}

void p(){
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << "[" << dp[i][j].max << "," << dp[i][j].min << "] ";
        }
        cout << "\n";
    }
}

int main() {
    Input();

    // set dp[i][i+1]
    for (int i = 1; i < N; i++) {
        ll a = simple_calc(num[i], opr[i], num[i+1]);
        dp[i][i+1] = {a, a};
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= N-i; j++) {
            int k = i+j;
            dp[j][k] = complex_calc(j, k);
        }
    }
    cout << dp[1][N].max << "\n";
}