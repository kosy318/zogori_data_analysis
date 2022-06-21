#include <iostream>
#include <vector>
#include "timebomb.h"

int myBox[5001];

int tournament(std::vector<std::vector<int>>& history, int left, int right) {
    
    if (left == right) {
        return myBox[left];
    }

    int leftResult = tournament(history, left, (left+right)/2);
    int rightResult = tournament(history, (left+right)/2+1, right);

    if (box_comp(myBox[leftResult], myBox[rightResult]) == 1) {
        history[leftResult].push_back(rightResult);
        return leftResult;
    }
    else {
        history[rightResult].push_back(leftResult);
        return rightResult;
    }
}

int re_tournament(const std::vector<int>& matchBox, int left, int right) {

    if (left == right) {
        return left;
    }

    int leftResult = re_tournament(matchBox, left, (left+right)/2);
    int rightResult = re_tournament(matchBox, (left+right)/2+1, right);

    if (box_comp(matchBox[leftResult], matchBox[rightResult]) == 1) {
        return leftResult;
    }
    else {
        return rightResult;
    }
}


int main() {
    box_ready();
    int N = box_size();

    for (int i=1; i<=N; i++) {
        myBox[i] = i;
    }

    std::vector<std::vector<int>> matchHistory(N+1, std::vector<int>(1, 0));

    int largestNumIdx = tournament(matchHistory, 1, N);
    int secondLargestNumIdx = matchHistory[largestNumIdx][re_tournament(matchHistory[largestNumIdx], 1, matchHistory[largestNumIdx].size()-1)];

    box_report(secondLargestNumIdx);

    return 0;
}