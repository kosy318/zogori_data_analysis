#include <iostream>
#include <string>

using namespace std;

int main() { 
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s, t;
        cin >> s;
        cin >> t;

        while (s.size() && t.size()) {
            if (s.back() == t.back()) {
                s.pop_back();
                t.pop_back();
            }
            else {
                if (s.size() == 1) {
                    s.pop_back();
                }
                else {
                    s.pop_back();
                    s.pop_back();
                }
            }
        }

        if (t.size() == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}