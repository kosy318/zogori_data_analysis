#include <iostream>
#include <string>
#include <cstdlib>

#define MAX 10001

using namespace std;

int b[MAX];

int tcase = 5;

int main()
{
    int num;
    cin >> num;

    for (int ca = 0; ca < tcase; ca++) {
        int count = 0;
        int n = 1;

        for (int i = 0; i < num; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < num;) {
            int blank[MAX];

            if (b[i] != n) {
                int temp = abs(b[i]);

                if (b[i] > 0) {
                    for (int j = i; j < num; j++) {
                        if (abs(b[j]) == n) {
                            temp = j + 1;
                            break;
                        }
                    }
                    for (int j = i, k = 0; j < temp; j++, k++) {
                        blank[j] = -b[i + k];
                    }
                    for (int j = temp - 1, k = 0; j >= i; j--, k++) {
                        b[i + k] = blank[j];
                    }
                }
                else if (b[i] < 0) {
                    int max = 0;
                    int max_index = 0;

                    for (int j = i; j < temp; j++) {
                        if (abs(b[j]) > abs(max)) {
                            max = abs(b[j]);
                            max_index = j;
                        }
                    }
                    for (int j = max_index, k = 0; j < max; j++, k++) {
                        blank[j] = -b[max_index + k];
                    }
                    for (int j = max - 1, k = 0; j >= max_index; j--, k++) {
                        b[max_index + k] = blank[j];
                    }
                }
                count++;
            }
            if (b[i] == n) {
                i++, n++;
            }

            if (count > 2) {
                break;
            }
        }

        if (count == 1) {
            cout << "one" << "\n";
        }
        else if (count == 2) {
            cout << "two" << "\n";
        }
        else if (count > 2) {
            cout << "over" << "\n";
        }
    }

    return 0;
}
