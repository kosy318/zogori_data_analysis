#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 1100;

int dp_cost[maxN];
int dp_date[maxN];

struct request {
    int b, e, c;
    
    bool operator<(const request r) const {
        return this->b > r.b;
    }
};

int main() {
	fastio;
    int N; cin >> N;
    priority_queue <request> PQ;

    int end_day = 0;
    memset(dp_cost, 0, sizeof(dp_cost));
    memset(dp_date, 0, sizeof(dp_date));

    for (int i = 1; i <= N; i++) {
        int b, e, c; cin >> b >> e >> c;
        PQ.push({b, e, c});

        end_day = max(end_day, e);
    }

    for (int i = 1; i <= end_day; i++) {
        if (!PQ.empty() && (i == PQ.top().b)) {
            request work = PQ.top();

            int today = work.b;
            int next  = work.e + 1;
            int cost  = work.c;

            if (dp_cost[today] != 0) cost -= 10;

            if (next <= end_day + 1) { // 일 함 해볼까
                if (dp_cost[next] == dp_cost[today] + cost) { // 하나마나 돈 똑같네 더 쉬는거 하자
                    dp_date[next] = min(dp_date[next], dp_date[today] + (next - today));
                }
                else if (dp_cost[next] < dp_cost[today] + cost) { // 이거 하면 돈 더 받는다 하자
                    dp_cost[next] = dp_cost[today] + cost;
                    dp_date[next] = dp_date[today] + (next - today);
                }
                // 해도 돈을 덜 주네 걍 하지말자
            }
            // 일 하지말자
            if (dp_cost[today + 1] < dp_cost[today]) {
                dp_cost[today + 1] = dp_cost[today];
                dp_date[today + 1] = dp_date[today];
            }
            //if (dp_cost[today + 1] == dp_cost[today]) { dp_date[today + 1] = min(dp_date[today + 1], dp_date[today]); }

            PQ.pop();
        } 
        else {
            int today = i;
            if (dp_cost[today + 1] == dp_cost[today]) {
                dp_date[today + 1] = min(dp_date[today + 1], dp_date[today]);
            }
            else if (dp_cost[today + 1] < dp_cost[today]) {
                dp_cost[today + 1] = dp_cost[today];
                dp_date[today + 1] = dp_date[today];
            }
        }

        if (!PQ.empty() && PQ.top().b == i) i--;
    }

	cout << dp_cost[end_day + 1] << " " << dp_date[end_day + 1] << "\n";
}

