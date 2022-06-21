#include "timebomb.h"
#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

vector<int> compareTwoBoxes(vector<int> boxList, vector<stack<int>> &compareHistory, int &maxHeavyBox, int &secondHeavyBox) {
    vector<int> remainBoxes;
    int result = 0;
    
    while(!boxList.empty()) {
        int heavyBox = boxList.back(); boxList.pop_back();
        
        if (boxList.empty()) {
            remainBoxes.push_back(heavyBox);
            break;
        }
        
        int lightBox = boxList.back(); boxList.pop_back();
        result = box_comp(heavyBox, lightBox);
        if (result == -1) swap(heavyBox, lightBox);

        compareHistory[heavyBox].push(lightBox);
        remainBoxes.push_back(heavyBox);
        
        if (boxList.empty()) {
            maxHeavyBox = heavyBox;
            secondHeavyBox = lightBox;
            break;
        }
    }
    
    return remainBoxes;
}

void compareAllBoxes(int N, vector<int> boxList, vector<stack<int>> &compareHistory, int &maxHeavyBox, int &secondHeavyBox) {
    while (N > 0) {
        boxList = compareTwoBoxes(boxList, compareHistory, maxHeavyBox, secondHeavyBox);
        N /= 2;
    }
}

void getSecondHeavyBox(vector<stack<int>> &compareHistory, int maxHeavyBox, int &secondHeavyBox) {
    while (!compareHistory[maxHeavyBox].empty()) {
        int currBox = compareHistory[maxHeavyBox].top();
        compareHistory[maxHeavyBox].pop();
        
        if (box_comp(secondHeavyBox, currBox) == -1) {
            secondHeavyBox = currBox;
        }
    }
}

int main(void) {
    int N;
    box_ready();
    N = box_size();
    
    int maxHeavyBox = 0;
    int secondHeavyBox = 0;
    
    vector<stack<int>> compareHistory(N + 1);
    vector<int> boxList;
    for (int i = 1; i <= N; i++) boxList.push_back(i);
    
    compareAllBoxes(N, boxList, compareHistory, maxHeavyBox, secondHeavyBox);
    getSecondHeavyBox(compareHistory, maxHeavyBox, secondHeavyBox);
    box_report(secondHeavyBox);
    
    return 0;
}
