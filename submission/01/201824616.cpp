#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int palin(string S) {
    string R = S;

    reverse(R.begin(), R.end());

    if (S.compare(R) == 0) return 1;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] != R[i]) {
            S.replace(i, 1, "");
            string S2 = S;
            reverse(S2.begin(), S2.end());

            if (S.compare(S2) == 0) return 2;

            R.replace(i, 1, "");
            string R2 = R;
            reverse(R2.begin(), R2.end());

            if (R.compare(R2) == 0) return 2;

            break;
        }
    }

    return 3;
}


int main()
{
    int N;

    cin >> N;

    string S;

    for (int i = 0; i < N; i++) {
        cin >> S;
        cout << palin(S) << "\n";
    }

    return 0;
}
