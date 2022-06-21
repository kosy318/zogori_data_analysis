#include <bits/stdc++.h>
#define MAX 101
using namespace std;
struct BEC{
    int b, e, c, wd;
    BEC(int x = 0, int y = 0, int z = 0) : b{x}, e{y}, c{z}, wd{y - x + 1} {}
};

int N;
BEC w[MAX];
int  cDp[MAX];
int wdDp[MAX];

bool cmp(BEC &x, BEC &y){
    if(x.e == y.e)
        return x.b < x.b;
    return x.e < y.e;    
}

void best(){
    cDp[0] = w[0].c;
    wdDp[0] = w[0].wd;
    int m, d;
    for(int i = 1; i < N; i++){
        m = w[i].c;
        d = w[i].wd;
        for(int j = i-1; j>= 0; j--){
            if(w[i].b > w[j].e && cDp[j] + w[i].c - 10 >= m){
                m = cDp[j] + w[i].c - 10;
                d = wdDp[j] + w[i].wd;
            }
        }
        if(cDp[i-1] < m || cDp[i-1] == m && wdDp[i-1] >= d){
            cDp[i] = m;
            wdDp[i] = d;
        } else if(cDp[i-1] == m && wdDp[i-1] < d || cDp[i-1] > m){
            cDp[i] = cDp[i-1];
            wdDp[i] = wdDp[i-1];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int x, y, z;
    for (int i = 0; i < N; i++){
        cin >> x >> y >> z;
        w[i] = BEC(x, y, z);
    }
    sort(w, w + N, cmp);
    best();
    cout << cDp[N-1] << ' ' << wdDp[N-1];
}