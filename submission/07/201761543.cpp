#include <bits/stdc++.h>
#define cost 10
using namespace std;
struct st {
    int s, e, c;
};
int DP[110], cnt[110], N;
vector<st> v;

bool compare(st a, st b) {
    if(a.s == b.s) return a.e < b.e;
    return a.s < b.s;
}

int dfs(int curr) {
    if(DP[curr] != -1) return DP[curr];
    DP[curr] = v[curr].c;
    cnt[curr] = v[curr].e - v[curr].s + 1;
    int maxi = 0, c = 0;
    for(int i=curr+1; i<N; i++) {
        if(v[i].s <= v[curr].e) continue;
        int next = dfs(i);
        if(maxi < next - cost) {
            maxi = next - cost;
            c = cnt[i];
        }
        else if(maxi == next-cost) c = min(c, cnt[i]);
    }
    DP[curr] += maxi;
    cnt[curr] += c;
    return DP[curr];
}

int main() {
    memset(DP, -1, sizeof(DP));
    memset(cnt, 0, sizeof(cnt));
    cin >> N;
    for(int i=0; i<N; i++) {
        st x;
        cin >> x.s >> x.e >> x.c;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), compare);
    int maxi = 0, idx;
    for(int i=0; i<N; i++) {
        if(maxi < dfs(i)) {
            maxi = DP[i];
            idx = i;
        }
    }
    cout << DP[idx] << " " << cnt[idx] << '\n';
}