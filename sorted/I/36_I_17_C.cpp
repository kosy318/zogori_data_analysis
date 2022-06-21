#include <bits/stdc++.h>

using namespace std;

struct line {
    int s, e;
};

line arr[100001];
int n;

bool check(long long v) {
    long long location = arr[0].s;
    for ( int i = 0; i < n-1; i++ ) {
        if ( arr[i+1].e < location + v )
            return false;
        if ( arr[i+1].s > location + v )
            location = arr[i+1].s;
        else
            location += v;
    }
    return true;
}

bool cmp(line a, line b) {
    return a.s < b.s;
}

int main() {
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        int s, d;
        cin >> s >> d;
        arr[i].s = s;
        arr[i].e = s+d;
    }
    sort(arr, arr+n, cmp);

    long long mi = 0, ma = 2e9;
    while ( mi < ma ) {
        long long mid = (ma+mi) / 2;
        if ( check(mid) )
            mi = mid+1;
        else
            ma = mid;
    }
    if ( check(mi) )
        cout << mi << endl;
    else
        cout << (mi-1) << endl;
}
