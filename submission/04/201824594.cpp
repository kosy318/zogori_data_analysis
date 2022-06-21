#include <vector>
#include "timebomb.h"

using namespace std;

int main(void) {
    int N, result;
    int winner[5001];
    vector<int> round[5001];

    box_ready();
    N = box_size();

    for (int i = 1; i <= N; ++i) {
        winner[i] = i;
    }

    while (!(N == 1)) {
        for (int t = 1; t <= N; t += 2) {
            if (t + 1 > N) {
                winner[(t + 1) / 2] = winner[t];
                break;
            }
            int i = winner[t];
            int j = winner[t + 1];
            round[i].push_back(j);
            round[j].push_back(i);
            result = box_comp(i, j);
            if (result == -1)
                winner[(t + 1) / 2] = j;
            else
                winner[(t + 1) / 2] = i;

        }
        N = (N + 1) / 2;
    }

    int first = winner[1];
    int second = round[first][0];
    for (int i = 1; i < round[first].size(); ++i) {
        result = box_comp(second, round[first][i]);
        if (result == -1)
            second = round[first][i];
    }
    box_report(second);
    return 0;
}