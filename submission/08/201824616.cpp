#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class str {
public:
    string s;

    str(string in) : s(in) {};

    bool operator< (const str &c) const{
        if (s.length() == (c.s).length()) return s.compare(c.s) > 0;
        else return s.length() < (c.s).length();
    }
};

int main()
{
    string S, T;

    cin >> S >> T;

    string arr[S.length() + 1][T.length() + 1];
    set<string> st;
    int st_i = 0;

    for (int i = 0; i <= S.length(); i++) {
        for (int j = 0; j <= T.length(); j++) {
            arr[i][j] = "";
        }
    }

    for (int i = 1; i <= T.length(); i++) {
        if (S[0] == T[i - 1]) {
            arr[1][i] = S[0];
            st.insert(arr[1][i]);
            st_i = 1;
        }
    }

    for (int i = 1; i <= S.length(); i++) {
        if (S[i - 1] == T[0]) {
            arr[i][1] = T[0];
            st.insert(arr[i][1]);
            st_i = 1;
        }
    }

    for (int i = 2; i <= S.length(); i++) {
        for (int j = 2; j <= T.length(); j++) {
            if (S[i - 1] == T[j - 1]) {
                arr[i][j] = max({str(arr[i - 2][j - 2]), str(arr[i - 2][j - 1]), str(arr[i - 1][j - 2]), str(arr[i - 1][j - 1])}).s + S[i - 1];

                if (arr[i][j].length() > st_i) {
                    st_i++;
                    st.clear();
                    st.insert(arr[i][j]);
                }
                else if (arr[i][j].length() == st_i) st.insert(arr[i][j]);
            }
        }
    }

    cout << *st.begin();
}
