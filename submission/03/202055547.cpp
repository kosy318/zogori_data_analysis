#include <iostream>
#include <vector>

using namespace std;

int k, l, r;

int next(vector<int> v, int pos) {
    while (pos < r-1 && v[pos+1] == v[pos]+1)
        pos++;
    return pos+1;
}


int solve() {
    vector<int> v(k);
    for (int &i: v) cin >> i;

    l = 0; r = k;

    for (int i=0; i<k; i++) {
        if (i+1 != v[i]) {
            l = i;
            break;
        }
    }
    for (int i=k-1; i>=0; i--) {
        if (i+1 != v[i]) {
            r = i+1;
            break;
        }
    }

    int pos = l;
    int up = 0, down = 0;
    int cutted[3];
    for (int i=0; i<3; i++) {
        cutted[i] = pos;
        if (v[pos] < 0) down++;
        else up++;
        pos = next(v, pos);
        if (pos == r) break;
    }

    if (pos != r) return 3;
    else if (down == 1 && up == 0) return 1;
    else if ((down == 1 && up == 1) || (down == 2 && up == 0)) return 2;
    else if (down == 2 && up == 1) {
        if (v[cutted[1]] == l+1 || v[cutted[2]-1] == r) return 3;
        else return 2;
    }
    else return 3;
}

int main() {
    cin >> k;
    int n = 5;
    while (n--) {
        int ret = solve();
        if (ret == 1) cout << "one" << endl;
        else if (ret == 2) cout << "two" << endl;
        else cout << "over" << endl;
    }
}
