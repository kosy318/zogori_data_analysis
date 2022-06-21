#include <iostream>
#include <vector>
using namespace std;
#define ASCII_a 97
#define MAX_NUM_CHAR 26


string s, t;
vector<vector<int>> vPos(MAX_NUM_CHAR, vector<int>());

inline int char_to_idx(char c) {
    return (int) c - ASCII_a;
}

bool backtrack(int depth, int cur_pos) {
    if (depth == t.size()) {
        if ((s.size() - cur_pos) % 2 == 1)  return true;
        else                                return false;
    }
    int idxChar = char_to_idx(t[depth]);
    for (int pos : vPos[idxChar]) {
        if ((pos > cur_pos) && ((pos - cur_pos) % 2 == 1))
            if (backtrack(depth + 1, pos))
                return true;
    }
    return false;
}

bool compute() {
    for (int idxChar = 0; idxChar < MAX_NUM_CHAR; idxChar++) {
        vPos[idxChar].clear();
    }
    for (int i = 0; i < s.size(); i++) {
        int idxChar = char_to_idx(s[i]);
        vPos[idxChar].push_back(i);
    }
    int idxFirstChar = char_to_idx(t[0]);
    for (int pos : vPos[idxFirstChar]) {
        if (backtrack(1, pos))
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        if (compute())  cout << "YES\n";
        else            cout << "NO\n";
    }
    return 0;
}