#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxT = 15;

struct task { int c, d; };

int myCompare(task a, task b) {
    if (a.c == b.c) {
        return a.d > b.d;
    }
    return a.c > b.c;
}

int N, T, k;

vector<task> conveyor;

vector< stack<task> > todo_list(maxT);
vector< queue<task> > deny_list(maxT);

int main() {
	fastio;
	cin >> N >> T >> k;
    for (int i = 0; i < N; i++) {
        int c, d; cin >> c >> d;
        conveyor.push_back({c, d});
    }

    sort(conveyor.begin(), conveyor.end(), myCompare);

    int firstMax = 0;
    for (int i = 0; i < N; i++) {
        int cc = conveyor[i].c;
        int dd = conveyor[i].d;

        bool flag = false;
        for (int i = dd; i >= 1; i--) {
            if (todo_list[i].size() < k) {
                todo_list[i].push({cc, dd});
                firstMax += cc;
                flag = true;
                break;
            }
        }

        if (!flag) {
            deny_list[dd].push({cc, dd});
        }
    }

    int secondMax = 0;
    for (int i = 1; i <= T; i++) {
        if (todo_list[i].size() != 0) {
            secondMax = max(secondMax, firstMax - todo_list[i].top().c);
        }
    }

    for (int i = 1; i <= T; i++) {
        if (deny_list[i].size() != 0) {
            task p = deny_list[i].front();

            for (int j = 1; j <= i; j++) {
                if (todo_list[j].size() != 0) {
                    int diff = todo_list[j].top().c - p.c;
                    if (diff != 0) {
                        secondMax = max(secondMax, firstMax - diff);
                    }
                }
            }
        }
    }

    cout << firstMax << " " << secondMax << "\n";
}