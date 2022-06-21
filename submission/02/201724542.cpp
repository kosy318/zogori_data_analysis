#include <bits/stdc++.h>
using namespace std;

bool backspace(string &src, string &dst, int src_idx, int dst_idx) {
    if (dst_idx == dst.length()) {
        if ((src.length() - 1 - src_idx) % 2 == 0) return true;
        else return false;
    }
    else {
        for (int i = src_idx + 1; i < src.length(); i++) {
            if (src[i] == dst[dst_idx]) {
                if ((i - src_idx) % 2 == 1 || (src_idx == -1 && (i - src_idx) % 2 == 0)) {
                    // cout << i << " " << dst_idx << endl;
                    if (backspace(src, dst, i, dst_idx + 1)) return true;
                }
            }
        }
    }
    return false;
}

void ans(string &source, string &target) {
    if (backspace(source, target, -1, 0)) cout << "YES\n";
    else cout << "NO\n";
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    string S, T;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S >> T;
        ans(S, T);
    }
    return 0;
}