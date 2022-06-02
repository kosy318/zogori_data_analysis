#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int b;
    int e;
    int w;
    int day;
}clean;

int dpw[101]{};
int dpd[101]{};
vector<clean> vec;

bool cmp(clean f, clean s) {
    if (f.e == s.e) {
        return f.b < s.b;
    }
    else return f.e < s.e;
}

void solve(int cnt) {
    dpw[1] = vec[1].w;
    dpd[1] = vec[1].day;
    int cmpw1 = 0, cmpw2 = 0;
    int cmpd1 = 0, cmpd2 = 0;
    for (int i = 2; i < cnt + 1; i++) {
        cmpw1 = dpw[i-1];
        cmpd1 = dpd[i-1];
        cmpw2 = vec[i].w;
        cmpd2 = vec[i].day;
        for (int j = i - 1; j > 0; j--) {
            if (vec[j].e < vec[i].b) {
                if (dpw[j] + vec[i].w - 10 > cmpw2) {
                    cmpw2 = dpw[j] + vec[i].w - 10;
                    cmpd2 = dpd[j] + vec[i].day;
                }
                else if (dpw[j] + vec[i].w - 10 == cmpw2) {
                    if (dpd[j] + vec[i].day < cmpd2) {
                        cmpw2 = dpw[j] + vec[i].w - 10;
                        cmpd2 = dpd[j] + vec[i].day;
                    }
                }
            }
            if (cmpw1 > cmpw2) {
                dpw[i] = cmpw1; dpd[i] = cmpd1;
            }
            else if (cmpw1 == cmpw2) {
                if (cmpd1 > cmpd2) {
                    dpw[i] = cmpw2; dpd[i] = cmpd2;
                }
                else {
                    dpw[i] = cmpw1; dpd[i] = cmpd1;
                }
            }
            else {
                dpw[i] = cmpw2;  dpd[i] = cmpd2;
            }
        }
    }
}

int main() {
    int k;
    cin >> k;
    vec.push_back({ 0,0,0,0 });
    for (int i = 0; i < k; i++) {
        int b, e, w;
        cin >> b >> e >> w;
        vec.push_back({ b,e,w,0 });
    }
    sort(begin(vec), end(vec), cmp);
    vector<clean>::iterator const itr = vec.begin();
    for_each(itr + 1, itr + vec.size(), [](auto& itr) {
        itr.day = itr.e - itr.b + 1;
        });
    solve(k);
    cout << dpw[k] << " " << dpd[k];
}
