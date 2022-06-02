#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int profit = 0;
int days = 0;

bool cmp(vector<int> &a, vector<int> &b) {
    if(a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

void calcMaxProfit(vector<vector<int>> &works) {
    // Sort by the end day.
    sort(works.begin(), works.end(), cmp);
    
    int maxDate = works[works.size() - 1][1];
    // memo[i][0]: to ith date, the max profit you can earn. (1-index)
    // memo[i][1]: work days.
    vector<vector<int>> memo(maxDate + 1, vector<int>(2, 0));
    
    for(int i=1, j=0; i<=maxDate; i++) {
        memo[i] = memo[i-1];
        while(j<works.size() && i == works[j][1]) {
            // case1: don't do jth work.
            int profit1 = memo[i][0];
            int days1 = memo[i][1];
            // case2: do jth work.
            int prevDate = works[j][0] - 1;
            int profit2 = memo[prevDate][0] + works[j][2];
            profit2 -= (memo[prevDate][1] > 0) ? 10 : 0;
            int days2 = memo[prevDate][1] + works[j][1] - works[j][0] + 1;
            
            if(profit1 > profit2 || (profit1 == profit2 && days1 < days2)) {
                memo[i][0] = profit1;
                memo[i][1] = days1;
            } else {
                memo[i][0] = profit2;
                memo[i][1] = days2;
            }
            j++;
        }
    }
    
    profit = memo[maxDate][0];
    days = memo[maxDate][1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int>> works;
    int N;
    cin >> N;
    while(N--) {
        vector<int> tmp;
        for(int i=0; i<3; i++) {
            int t;
            cin >> t;
            tmp.push_back(t);
        }
        works.push_back(tmp);
    }
    calcMaxProfit(works);
    cout << profit << " " << days << "\n";
}