#include <iostream>
#include "timebomb.h"
#include <vector>

using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

vector<int> idx;

int main(void) {
    int N, result, This;
    
    box_ready();
    N = box_size();

    for (int i = 0; i <= N; i++) {
        idx.push_back(i);
    }

    for (int i = 1; i <= 2*N-3; i = i+2) {
        result = box_comp(idx[i], idx[i+1]);
        if (result == 1) {
            idx.push_back(idx[i]);
        }
        else if (result == -1) {
            idx.push_back(idx[i+1]);
        }
    }

    int parent = 1;
    int child = 2;
    vector<int> second;
    while (child < 2*N) {
        if (idx[2*N - parent] == idx[2*N - child]) {
            second.push_back(idx[2*N - (child+1)]);
            parent = child;
            child = 2*parent;
        }
        else if (idx[2*N - parent] == idx[2*N - (child+1)]) {
            second.push_back(idx[2*N - child]);
            parent = child+1;
            child = 2*parent;
        }
    }

    This = second[0];
    for (int i = 1; i < second.size(); i++) {
        result = box_comp(This, second[i]);
        if (result == -1)
            This = second[i];
    }

    box_report(This);

    return 0;
}