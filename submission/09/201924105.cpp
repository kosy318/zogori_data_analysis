#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

long long calc(long long x, long long y, char op) {
    switch(op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        default:
            return -1;
    }
}

long long findMaxMoney(vector<int> &nums, vector<char> &ops) {
    int n = nums.size();
    // memo[i][j]: caculate[i:j]
    vector<vector<long long>> maxMemo(n, vector<long long>(n, LLONG_MIN));
    vector<vector<long long>> minMemo(n, vector<long long>(n, LLONG_MAX));
    
    // Base condition
    for(int i=0; i<n; i++) {
        maxMemo[i][i] = minMemo[i][i] = nums[i];
    }

    // Dynamic programming
    for(int j=1; j<n; j++) {
        for(int i=j-1; i>=0; i--) {
            int cnt = j-i;
            for(int k=0; k<cnt; k++) {
                vector<long long> candidates;
                candidates.push_back(calc(maxMemo[i][j-cnt+k], maxMemo[i+k+1][j], ops[i+k]));
                candidates.push_back(calc(maxMemo[i][j-cnt+k], minMemo[i+k+1][j], ops[i+k]));
                candidates.push_back(calc(minMemo[i][j-cnt+k], maxMemo[i+k+1][j], ops[i+k]));
                candidates.push_back(calc(minMemo[i][j-cnt+k], minMemo[i+k+1][j], ops[i+k]));
                sort(candidates.begin(), candidates.end());


                maxMemo[i][j] = max(candidates[3], maxMemo[i][j]);
                minMemo[i][j] = min(candidates[0], minMemo[i][j]);   
            }
        }
    }
    return maxMemo[0][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> nums;
    vector<char> ops;
    while(1) {
        int n;
        char c;
        cin >> n;
        nums.push_back(n);
        cin >> c;
        if(cin.eof())
            break;
        ops.push_back(c);
    }
    cout << findMaxMoney(nums, ops) << "\n";
}