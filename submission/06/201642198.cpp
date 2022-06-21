#include <iostream>
#include <algorithm>
using namespace std;
#define INIT_VAL "-"
#define EMPTY_STR ""
#define MAX_LEN 1000
string S;
string cache[MAX_LEN][MAX_LEN];


string superior(const string a, const string b) {
    if (a.size() == b.size())       return min(a, b);
    else if (a.size() > b.size())   return a;
    else                            return b;
}


string calcLPS(const int lp, const int rp) {
    if (cache[lp][rp] != INIT_VAL)
        return cache[lp][rp];
    cache[lp][rp] = superior(calcLPS(lp+1, rp), calcLPS(lp, rp-1));
    if (S[lp] == S[rp])
        cache[lp][rp] = superior(cache[lp][rp], S[lp] + calcLPS(lp+1, rp-1) + S[rp]);
    return cache[lp][rp];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S;

    fill(cache[0], cache[MAX_LEN-1], INIT_VAL);
    for (int i = 0; i < S.size(); i++)
        cache[i][i] = S[i];
    for (int i = 1; i < S.size(); i++)
        cache[i][i-1] = EMPTY_STR;
    cout << calcLPS(0, S.size() - 1);
    return 0;
}