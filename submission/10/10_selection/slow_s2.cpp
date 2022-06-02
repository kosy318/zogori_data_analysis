#include <iostream>
#include <queue>

using namespace std;

int N, T, k, c, d;
priority_queue<pair<int, int>> task;

int main()
{
    cin >> N >> T >> k;
    int arr[k][T];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < T; j++) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> c >> d;
        task.push({c, d});
    }

    int min_dif = 100, dif, max_sum = 0;

    while (!task.empty()) {
        dif = 100;
        bool f = 0;

        for (int i = task.top().second - 1; i >= 0; i--) {
            for (int j = 0; j < k; j++) {
                if (arr[j][i] == 0) {
                    arr[j][i] = task.top().first;
                    if (min_dif > arr[j][i]) min_dif = arr[j][i];
                    max_sum += arr[j][i];
                    f = 1;
                    break;
                }
                else if (dif > (arr[j][i] - task.top().first) && (arr[j][i] - task.top().first) != 0) dif = (arr[j][i] - task.top().first);
            }
            if (f) break;
        }

        if (!f && min_dif > dif) min_dif = dif;
        task.pop();
    }

    cout << max_sum << " " << max_sum - min_dif;
}