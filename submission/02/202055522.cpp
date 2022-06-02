#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    for (int n = 0; n < N; n++) {
        string s, t; cin >> s >> t;
        int index;
        bool state = true;
        for (int i = t.length() - 1; i >= 0; i--) {
            if (s.rfind(t[i]) != string::npos) {
                index = s.rfind(t[i]);
                while (((s.length() - 1) - index) % 2 != 0) {
                    if (index != 0 && (s.rfind(t[i], index - 1) != string::npos)) {
                        index = s.rfind(t[i], index - 1);
                    }
                    else {
                        state = false;
                        break;
                    }
                }
                if (state) s = s.substr(0, index);
                else break;
            }
            else {
                state = false;
                break;
            }
        }

        if (state) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
