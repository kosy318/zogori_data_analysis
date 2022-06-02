#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num[30];
char ope[29];
long long dp_max[30][30];
long long dp_min[30][30];

int INF = 1234567890;

long long cal(long long a, long long b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
}

int main() {
    cin >> num[0];
    int n = 1;
    while (cin >> ope[n-1] && ope[n-1] != ';')
        cin >> num[n++];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            dp_max[i][j] = -INF;
            dp_min[i][j] = INF;
        }
    }

    for (int i=0; i<n; i++) {
        dp_max[i][i] = num[i];
        dp_min[i][i] = num[i];
    }

    for (int range=2; range<=n; range++) {
        for (int i=0; i<n-range+1; i++) {
            vector<long long> tmp;
            for (int k=i; k<i+range-1; k++) {
                tmp.push_back(cal(dp_max[i][k], dp_max[k+1][i+range-1], ope[k]));
                tmp.push_back(cal(dp_max[i][k], dp_min[k+1][i+range-1], ope[k]));
                tmp.push_back(cal(dp_min[i][k], dp_max[k+1][i+range-1], ope[k]));
                tmp.push_back(cal(dp_min[i][k], dp_min[k+1][i+range-1], ope[k]));
            }
            sort(tmp.begin(), tmp.end());
            dp_max[i][i+range-1] = tmp.back();
            dp_min[i][i+range-1] = tmp.front();
        }
    }

    cout << dp_max[0][n-1] << endl;
}
