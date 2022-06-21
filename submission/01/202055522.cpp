#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        bool state = true;
        int result = 1;
        int point1 = 0;
        int point2 = str.length() - 1;
        for (int j = 0; j <= str.length() / 2; j++) {
            if (str[point1] != str[point2]) {
                if (state && str[point1] == str[point2-1] && str[point1+1] == str[point2]) {
                    string temp = str;
                    reverse(temp.begin()+point1, temp.begin()+point2);
                    if (temp == str) {
                        result = 2;
                        break;
                    }
                    else {
                        temp = str;
                        reverse(temp.begin()+point1+1, temp.begin()+point2+1);
                        if (temp == str) {
                            result = 2;
                            break;
                        }
                        else {
                            result = 3;
                            break;
                        }
                    }

                }
                else if (state && str[point1] == str[point2-1]) {
                    state = false;
                    result = 2;
                    point2--;
                }
                else if (state && str[point1+1] == str[point2]) {
                    state = false;
                    result = 2;
                    point1++;
                }
                else {
                    result = 3;
                    break;
                }
            }
            else {
                point1++;
                point2--;
            }
        }
        cout << result << '\n';
    }
}
