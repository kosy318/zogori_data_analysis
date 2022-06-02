#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    cin >> num;

    for (int n = 0; n < num; n++) {
        string s, t;
        cin >> s >> t;

        string u;

        int i = 0, j = 0;

        for (int a = 0; a < s.length(); a++) {
            for (i = a; i < s.length();) {
                if (s[i] == t[j]) {
                    u += s[i];

                    if (u == t) {
                        int num = s.length() - 1 - i;
                        if ((num % 2) == 0) {
                            break;
                        }
                        else {
                            u = "";
                            j = 0;
                            break;
                        }
                    }
                    i++, j++;
                }
                else {
                    if (j != 0) {
                        i += 2;
                    }
                    else {
                        i++;
                    }
                }
            }
            if (u == t) {
                break;
            }
            else {
                u = "";
                j = 0;
            }
        }

        if (u == t) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
