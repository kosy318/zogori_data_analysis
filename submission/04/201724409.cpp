#include "timebomb.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N;
    box_ready();
    N = box_size();

    vector<int> v;
    vector<pair<int, int>> fight;

    for (int i = 1; i <= N; i++) {
        v.push_back(i);
    }

    while (N > 1) {
        for (int i = 0; i < int(N/2); i++) {
            if (box_comp(v[i], v[i+1]) == 1) {
                fight.push_back(pair<int, int>(v[i], v[i+1]));
                v.erase(v.begin() + i+1);
            }
            else {
                fight.push_back(pair<int, int>(v[i+1], v[i]));
                v.erase(v.begin() + i);
            }
        }

        if (N%2 == 1) N += 1;
        N = int(N/2);
    }

    int max_index = v[0];
    vector<int> v2;

    for (int i = 0; i < fight.size(); i++) {
        if (fight[i].first == max_index) {
            v2.push_back(fight[i].second);
        }
    }


    int second_max = v2[0];
    int second_max_index = 0;
    for(int i = 1; i < v2.size(); i++) {
        if (box_comp(v2[second_max_index], v2[i]) == -1) {
            second_max_index = i;
            second_max = v2[i];
        }
    }

    box_report(second_max);
    return 0;
}