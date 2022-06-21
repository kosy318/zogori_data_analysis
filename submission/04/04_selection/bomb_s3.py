#include "timebomb.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> tourn[5001];

int getMax(int left, int right) {
    if(left==right) return left;
    int mid = (left+right)/2;
    int leftMax = getMax(left,mid);
    int rightMax = getMax(mid+1,right);
    if(box_comp(leftMax,rightMax)==1) {
        tourn[leftMax].push_back(rightMax);
        return leftMax;
    }
    tourn[rightMax].push_back(leftMax);
    return rightMax;
}

int main() {
    int N,first,second;

    box_ready();
    N = box_size();

    first = getMax(1,N);
    
    second = tourn[first][0];
    for(int i=1; i<tourn[first].size(); i++) {
        if(box_comp(tourn[first][i],second)==1)
            second = tourn[first][i];
    }

    box_report(second);
}