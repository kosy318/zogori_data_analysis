#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define X first
#define Y second

const int ADD_COST = 10;
const int MAX_DAY = 365 * 3;
const pi INIT = {-1, -1};
map<int, vector<pi>> mTask;
vector<pi> cache (MAX_DAY + 1, INIT);
pi answer = INIT;

void getInput() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int b, e, c; cin >> b >> e >> c;
        if (mTask.find(e) == mTask.end())   mTask[e] = {make_pair(b, c)};
        else                                mTask[e].push_back(make_pair(b, c));
    }
}

pi getBetter(const pi& a, const pi& b) {
    if (a.X > b.X)      return a;
    else if (a.X < b.X) return b;
    else {
        if (a.Y >= b.Y) return b;
        else            return a;
    }
}

pi getOptimum(int endDay) {
    if (cache[endDay] != INIT)  return cache[endDay];
    
    cache[endDay] = getOptimum(endDay-1);
    for (auto& e : mTask[endDay]) {
        int b = e.X, c = e.Y;
        pi prevOptimum = getOptimum(b-1);
        int profitAdd = (prevOptimum.X == 0) ? c : c - ADD_COST;
        int workdayAdd = endDay - b + 1;
        cache[endDay] = getBetter(cache[endDay], {prevOptimum.X + profitAdd, prevOptimum.Y + workdayAdd});
    }
    return cache[endDay];
}

void compute() {
    cache[0] = make_pair(0, 0);
    answer = getOptimum(MAX_DAY);
}

void printOutput() {
    cout << answer.X << ' ' << answer.Y << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getInput();
    compute();
    printOutput();
    return 0;
}