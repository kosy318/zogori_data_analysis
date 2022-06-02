#include <bits/stdc++.h>
using namespace std;

struct task {
    int cost;
    int deadline;
};

bool operator < (const task& x, const task& y) {
    return x.deadline < y.deadline;
}

const int MAX_T = 10;
int n, t, k;
int numTask[MAX_T + 1];
vector<task> vTask;

void readInput() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> t >> k;
    memset(numTask, 0, t + 1);
    for (int i = 0; i < n; i++) {
        int c, d; cin >> c >> d;
        vTask.push_back(task{c, d});
        numTask[d]++;
    }
}

int getFirstMax(int slowTask) {
    priority_queue<task, vector<task>, less<task>> pqDeadline;
    priority_queue<int, vector<int>, less<int>> pqCost;
    for (auto t : vTask)
        pqDeadline.push(t);
    int maxProfit = 0, day = t + 1, cntTask = 0;
    int tmpCost, cntDelayed = 0;
    while (--day > 0) {
        while (!pqDeadline.empty() && pqDeadline.top().deadline == day) {
            pqCost.push(pqDeadline.top().cost);
            pqDeadline.pop();
        }
        int cntMachine = 0;
        while (!pqCost.empty() && cntMachine < k) {
            if (++cntTask == slowTask) {
                tmpCost = pqCost.top();
                pqCost.pop();
                cntDelayed++;
                while (!pqCost.empty() && pqCost.top() == tmpCost) {
                    pqCost.pop();
                    cntDelayed++;
                }
                continue;
            }
            maxProfit += pqCost.top();
            pqCost.pop();
            cntMachine++;
        }
        while (numTask[day-1] + pqCost.size() >= k && cntDelayed) {
            pqCost.push(tmpCost);
            cntDelayed--;
        }
    }
    return maxProfit;
}

int getSecondMax(int firstMaxi) {
    int secondMaxi = 0;
    for (int i = t * k; i > 0; i--) {
        int currMaxi = getFirstMax(i);
        if (secondMaxi < currMaxi && currMaxi < firstMaxi)
            secondMaxi = currMaxi;
    }
    return secondMaxi;
}

int main() {
    readInput();
    int firstMaxi = getFirstMax(0);
    int secondMaxi = getSecondMax(firstMaxi);
    cout << firstMaxi << ' ' << secondMaxi;
}