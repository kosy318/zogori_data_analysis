#include <iostream>
#include "timebomb.h"
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int N, result, This;

    box_ready();
    N = box_size();

    vector<vector<int>> v(N + 1);
    vector<int> arr;
    vector<int> t_arr;

    for (int i = 1; i <= N; i += 2) {
        if (i + 1 > N) arr.push_back(i);
        else {
            result = box_comp(i, i + 1);
            if (result == -1) {
                v[i + 1].push_back(i);
                arr.push_back(i + 1);
            }
            else {
                v[i].push_back(i + 1);
                arr.push_back(i);
            }
        }
    }

    N = arr.size();
    while (N > 1) {
        for (int i = 0; i < N; i += 2) {
            if (i + 1 >= N) t_arr.push_back(arr[i]);
            else {
                int a = arr[i];
                int b = arr[i + 1];
                result = box_comp(a, b);

                if (result == -1) {
                    v[b].push_back(a);
                    t_arr.push_back(b);
                }
                else {
                    v[a].push_back(b);
                    t_arr.push_back(a);
                }
            }
        }
        arr = t_arr;
        t_arr.clear();
        N = arr.size();
    }

    arr = v[arr[0]];
    N = arr.size();
    while (N > 1) {
        for (int i = 0; i < N; i += 2) {
            if (i + 1 >= N) t_arr.push_back(arr[i]);
            else {
                int a = arr[i];
                int b = arr[i + 1];
                result = box_comp(a, b);

                if (result == -1) t_arr.push_back(b);
                else t_arr.push_back(a);
            }
        }
        arr = t_arr;
        t_arr.clear();
        N = arr.size();
    }

    This = arr[0];
    box_report(This);
}
