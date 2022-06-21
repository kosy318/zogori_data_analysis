#include <iostream>
#include <string>
#include <vector>

using namespace std;

int next_index(string s, string t, int t_loc, int start) {
    for (int i = start; i < s.length(); i++) {
        if (s[i] == t[t_loc]) {
            return i;
        }
    }

    return -1;
}

bool bk(string s, string t) {
    vector<int> index;

    if (s.length() < t.length()) return 0;

    for (int i = 0; i < t.length(); i++) {
        if (i == 0) index.push_back(next_index(s, t, i, 0));
        else index.push_back(next_index(s, t, i, index[i - 1] + 1));
    }

    while (true) {
        bool fail = 0;

        if (index.back() == -1) return 0;

        if ((s.length() - (index.back() + 1)) % 2 == 1) fail = 1;

        else if (index.size() > 1) {
            for (int i = 1; i < index.size(); i++) {
                if ((index[i] - index[i - 1]) % 2 == 0) {
                    fail = 1;
                    break;
                }
            }
        }

        if (fail == 1) {
            for (int i = index.size() - 1; i >= 0; i--) {
                for (int j = i; j < index.size(); j++) {
                    if (j == i) index[j] = next_index(s, t, j, index[j] + 1);
                    else if (index[j - 1] == -1) index[j] = -1;
                    else index[j] = next_index(s, t, j, index[j - 1] + 1);
                }

                if (index.back() != -1) break;
            }
        }

        else return 1;
    }
}

int main()
{
    int tc;

    cin >> tc;

    string s, t;

    for (int i = 0; i < tc; i++) {
        cin >> s >> t;

        if (bk(s, t)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
