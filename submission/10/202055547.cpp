#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int n, t, k;
int INF = 1234567890;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second != p2.second) return p1.second > p2.second;
    else return p1.first > p2.first;
}

int find_max(vector<pair<int, int>> v, vector<int> &min_v) {
    sort(v.begin(), v.end(), cmp);
    priority_queue<int, vector<int>, less<int>> pq;

    int idx = 0;
    int sum = 0;
    for (int i=t; i>0; i--) {
        while (v[idx].second == i) {
            if (idx == v.size()) break;
            pq.push(v[idx++].first);
        }

        for (int j=0; j<k; j++) {
            if (!pq.empty()) {
                sum += pq.top();
                min_v[i] = min(min_v[i], pq.top());
                pq.pop();
            }
        }
    }
    return sum;
}

int main() {
    cin >> n >> t >> k;
    vector<pair<int, int>> v;
    vector<int> min_v(t+1, INF);

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    int ans = find_max(v, min_v);

    for (int i=2; i<=t; i++) {
        min_v[i] = min(min_v[i-1], min_v[i]);
    }

    int diff = INF;
    for (int i=1; i<=t; i++) {
        for (int j=0; j<n; j++) {
            if (v[j].second == i && v[j].first < min_v[i]) {
                diff = min(diff, min_v[i] - v[j].first);
            }
        }
    }

    min_v[0] = diff;
    cout << ans << " " << ans - *min_element(min_v.begin(), min_v.end());
}
