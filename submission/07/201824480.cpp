#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct clean {
    int b, e, j;
};

int N;
int dp_j[365 * 3 + 1] = { 0, };
int dp_day[365 * 3 + 1] = { 0, };
vector<clean> cl[365 * 3 + 1];
vector<clean> info;

bool cmp(const clean& a, const clean& b) {
    return a.e < b.e;
}

int main() {
    cin >> N;
    int b_t, e_t, j_t;
    for (int i = 0; i < N; i++) {
        cin >> b_t >> e_t >> j_t;
        info.push_back({ b_t, e_t, j_t });
    }
    sort(info.begin(), info.end(), cmp);

    for (auto c : info)
        cl[c.e].push_back(c);


    int lastmax = 0;
    int lastmaxday = 0;
    int lastday = info.back().e;
    for (int i = 1; i <= lastday; i++) {
        if (cl[i].empty()) {
            dp_j[i] = lastmax;
            dp_day[i] = lastmaxday;
        }
        else {
            dp_j[i] = lastmax;
            dp_day[i] = lastmaxday;
            for (auto c : cl[i]) {
                if (!dp_day[c.b - 1]) {
                    if (dp_j[i] < dp_j[c.b - 1] + c.j) {
                        dp_j[i] = dp_j[c.b - 1] + c.j;
                        dp_day[i] = dp_day[c.b - 1] + c.e - c.b + 1;
                    }
                    else if (dp_j[i] == dp_j[c.b - 1] + c.j)
                        dp_day[i] = min(dp_day[i], dp_day[c.b - 1] + c.e - c.b + 1);
                }
                else {
                    if (dp_j[i] < dp_j[c.b - 1] + c.j - 10) {
                        dp_j[i] = dp_j[c.b - 1] + c.j - 10;
                        dp_day[i] = dp_day[c.b - 1] + c.e - c.b + 1;
                    }
                    else if (dp_j[i] == dp_j[c.b - 1] + c.j)
                        dp_day[i] = min(dp_day[i], dp_day[c.b - 1] + c.e - c.b + 1);
                }
            }
            lastmax = dp_j[i];
            lastmaxday = dp_day[i];
        }
    }

    cout << dp_j[lastday] << " " << dp_day[lastday] << endl;
}