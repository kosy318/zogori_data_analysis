#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

// jobList: the list of jobs which make profits max
vector<int> jobList;
bool isRecord = true;
int firstMax = 0;
int secondMax = 0;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int calcProfit(vector<pair<int, int>> &profits, int T, int k) {
    vector<vector<bool>> schedule(T, vector<bool>(k, false));
    int cnt = 0;
    int pIdx = 0;
    int totalProf = 0;
    // cnt: number of jobs you decide to do
    while(cnt < T*k && pIdx < profits.size()) {
        int c = profits[pIdx].first;
        int d = profits[pIdx].second;
        // i: date in schedule
        // j: number of machines in schedule
        for(int i=d-1, j=0; i>=0 && j<k; j++) {
            if(!schedule[i][j]) {
                schedule[i][j] = true;
                totalProf += c;
                cnt++;
                if(isRecord) {
                   jobList.push_back(pIdx);
                }
                break;
            }
            if(j == k-1) {
                i--;
                j = -1;
            }
        }
        pIdx++;
    }
    return totalProf;
}

void doSlowdown(vector<pair<int, int>> &profits, int T, int k) {
    sort(profits.begin(), profits.end(), cmp);
    firstMax = calcProfit(profits, T, k);
    isRecord = false;
    
    for(int i=0; i<jobList.size(); i++) {
        auto copyProf = profits;
        copyProf.erase(copyProf.begin() + jobList[i]);
        int temp = calcProfit(copyProf, T, k);
        while(temp == firstMax) {
            copyProf.erase(copyProf.begin() + jobList[i]);
            temp = calcProfit(copyProf, T, k);
        }
        secondMax = secondMax < temp ? temp : secondMax;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, T, k;
    vector<pair<int, int>> profits;
    cin >> N >> T >> k;
    while(N--) {
        int c, d;
        cin >> c >> d;
        profits.push_back(pair<int, int>(c, d));
    }
    doSlowdown(profits, T, k);
    cout << firstMax << " " << secondMax << endl;
}