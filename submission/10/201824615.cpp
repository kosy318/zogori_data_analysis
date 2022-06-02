#include <bits/stdc++.h>
using namespace std;
int N, T, K, C, D;

int getSum(vector<vector<int>> &machines) {
    int sum = 0;
    for(auto &machine : machines) {
        int tmp_sum = 0;
        for(auto &w : machine) tmp_sum += w;
        sum += tmp_sum;
    }
    return sum;
}

pair<int, int> getGreedyAnswer(vector<pair<int, int>> &tasks) {
    int c, d;
    int last = 0;
    vector<vector<int>> machines(T, vector<int>());
    vector<pair<int, int>> margins;

    for(int i=0;i<N;i++) {
        tie(c, d) = tasks[i];
        bool flag = true;

        for(int j=d-1;j>=0;j--) {

            if( machines[j].size() < K ||
               c > *min_element(machines[j].begin(), machines[j].end()))
            {
                flag = false;
                machines[j].push_back(c);
                sort(machines[j].begin(), machines[j].end(), greater<int>());
                machines[j].resize(K);
                break;
            }
        }
        if(flag) margins.emplace_back(c, d);
    }
    int result = getSum(machines), second = INT_MAX;

    for(auto &margin : margins) {
        tie(c, d) = margin;
        for(int j=d-1;j>=0;j--)
            if(machines[j][K-1] != c)
                second = min(second, machines[j][K-1]-c);
    }
    for(auto &m : machines)
        for(auto &w : m) 
            if(w) second = min(second, w);
    return {result, result-second};
}

int main() {
    vector<pair<int, int>> tasks;
    cin >> N >> T >> K;
    while(cin >> C >> D) tasks.emplace_back(C, D);
    sort(tasks.begin(), tasks.end(), greater<pair<int, int>>());

    // for(auto task : tasks)
    //     cout << task.first << ' ' << task.second << '\n';cout << "-------\n";

    auto result = getGreedyAnswer(tasks);
    cout << result.first << ' ' << result.second;
}  