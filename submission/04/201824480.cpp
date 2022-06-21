#include "timebomb.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> compareIndex[5001];

int searchMaxIndex(int low, int high) {
    int mid = (low + high) / 2;
    if (low == high)
        return low;
    else {
        int leftMaxIndex = searchMaxIndex(low, mid);
        int rightMaxIndex = searchMaxIndex(mid + 1, high);
        int result = box_comp(leftMaxIndex, rightMaxIndex);
        compareIndex[leftMaxIndex].push_back(rightMaxIndex);
        compareIndex[rightMaxIndex].push_back(leftMaxIndex);

        if(result == 1)
            return leftMaxIndex;
        else
            return rightMaxIndex;
    }
}

int main() {
    int N, ans;

    box_ready();
    N = box_size();
    int mid = N / 2;

    int leftIndex = searchMaxIndex(1, mid);
    int rightIndex = searchMaxIndex(mid+1, N);

    int result = box_comp(leftIndex, rightIndex);

    int index = 0;
    if(result == 1) {
        compareIndex[leftIndex].push_back(rightIndex);
        ans = compareIndex[leftIndex][index];
        for(int i = 0; i < compareIndex[leftIndex].size(); i++) {
            if(box_comp(compareIndex[leftIndex][index], compareIndex[leftIndex][i]) == -1) {
                index = i;
                ans = compareIndex[leftIndex][index];
            }
        }
    }
    else {
        compareIndex[rightIndex].push_back(leftIndex);
        ans = compareIndex[rightIndex][index];
        for(int i = 0; i < compareIndex[rightIndex].size(); i++) {
            if(box_comp(compareIndex[rightIndex][index], compareIndex[rightIndex][i]) == -1) {
                index = i;
                ans = compareIndex[rightIndex][index];
            }
        }
    }
    box_report(ans);
}
