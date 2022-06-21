#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 123;

int m, n;
int x[N];
int c[N];

int l[N];
int r[N];

int gid[N];

int dp[N];
int prefix[N];
int suffix[N];

int t[N];

void build(int v = 1, int tl = 1, int tr = n) {
    if (tl == tr) t[v] = 1e9;
    else {
        int mid = (tl + tr) / 2;
        build(v + v, tl, mid);
        build(v + v + 1, mid + 1, tr);
        t[v] = 1e9;
    }
}

void upd(int pos, int val, int v = 1, int tl = 1, int tr = n) {
    if (tl == tr) t[v] = val;
    else {
        int mid = (tl + tr) / 2;
        if (pos <= mid) upd(pos, val, v + v, tl, mid);
        else upd(pos, val, v + v + 1, mid + 1, tr);
        t[v] = min(t[v + v], t[v + v + 1]);
    }
}

int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
    if (tl > r || tr < l) return 1e9;
    if (l <= tl && tr <= r) return t[v];
    int mid = (tl + tr) / 2;
    return min(get(l, r, v + v, tl, mid), get(l, r, v + v + 1, mid + 1, tr));
}

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif // LOCAL


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 1; i <= n; i++) {
        if (c[i] == c[i - 1])
            l[i] = l[i - 1];
        else
            l[i] = i - 1;
    }
    for (int i = n; i > 0; i--) {
        if (c[i] == c[i + 1])
            r[i] = r[i + 1];
        else
            r[i] = i + 1;
    }

    build();
    for (int st = 1; st <= n; st = r[st]) {
        for (int i = st; i < r[st]; i++) {
            // previous is in same group
            dp[i] = 1e9;

            if (i > st)
                dp[i] = prefix[i - 1] + 1;

            // previous is in previous group
            if (st > 1) {
                int from_x = x[st - 1] - (x[i] - x[st - 1]);
                int to_x = x[st] - (x[i] - x[st]);
                //[from_x...x[st-1]
                int from_pos = lower_bound(x + 1, x + n + 1, from_x) - x;
                int to_pos = upper_bound(x + 1, x + n + 1, to_x) - x - 1;
                from_pos = max(from_pos, l[st - 1] + 1);
                to_pos = min(to_pos, r[st - 1] - 1);
                if (from_pos <= to_pos) {
                    //cout << "get " << from_pos << ' ' << to_pos << ' ' << get(from_pos, to_pos) << endl;
                    dp[i] = min(dp[i], 1 + get(from_pos, to_pos));
                }
                //for (int j = from_pos; j <= to_pos; j++)
                //    dp[i] = min(dp[i], dp[j] + 1);
            } else {
                dp[i] = 1;
            }

            if (i > st)
                prefix[i] = min(prefix[i - 1], dp[i]);
            else
                prefix[i] = dp[i];

        }
        for (int i = r[st] - 1; i >= st; i--) {
            if (i == r[st] - 1) suffix[i] = dp[i];
            else suffix[i] = min(suffix[i + 1], dp[i]);

            //cout << "upd " << i << ' ' << dp[i] << endl;
            upd(i, dp[i]);
        }
        //cout << "group\n";
        //for (int i = st; i < r[st]; i++) cout << i << ' ' << dp[i] << endl;

    }

    int ans = dp[n];
    for (int i = l[n] + 1; i <= n; i++) ans = min(ans, dp[i]);
    cout << ans;
    return 0;
}
