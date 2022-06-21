#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;
priority_queue<ti, vector<ti>, greater<ti>> pq;
pair<int, int> dp[1100];
int N, b, e, c, day = 0;

void input() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    while(cin >> b >> e >> c) {
        pq.emplace(b, e, c);
        day = max(day, e+1);
    }
}
void memoize() {
    dp[0].first = 10;
    for(int i=1;i<=day;i++) {
        dp[i] = max(dp[i-1], dp[i]);
        while(!pq.empty()) {
            tie(b, e, c) = pq.top();
            if(b != i) break;
            dp[e+1] = max(dp[e+1], {dp[b].first+c-10, dp[b].second-(e+1-b)});
            pq.pop();
        }
    }
}

int main() {
    input();
    memoize();
    printf("%d %d", dp[day].first, -dp[day].second);
}  