#include <iostream>
#include <vector>
#include "timebomb.h"

using namespace std;

vector<int> bombs;

int getSecondMax(int start, int end) {
    if(end==2) {
        if (box_comp(bombs[1],bombs[2])==1)
            return bombs[2];
        return bombs[1];
    }

    int pivot = bombs[(start+end)/2];

    vector<int> lower,higher;

    for(int i=start; i<=end; i++) {
        if(bombs[i]==pivot)
            continue;
        int compare = box_comp(bombs[i],pivot);
        if(compare == -1) {
            lower.push_back(bombs[i]);
        }
        else if(compare == 1) {
            higher.push_back(bombs[i]);
        }
    }

    int pivot_index = start+higher.size();

    if(pivot_index > 2) {
        for(int i=0; i<higher.size(); i++) {
            bombs[start+i] = higher[i];
        }
        return getSecondMax(start, pivot_index-1);
        cout << start << " " << pivot_index-1 << endl;
    }
    else if(pivot_index == 2) {
        return pivot;
    }
    else {
        cout << "right\n";
        for(int i=0; i<lower.size(); i++) {
            bombs[pivot_index+1+i] = lower[i];
        }
        return getSecondMax(pivot_index+1, end);
    }
}

int main() {
    int N;

    box_ready();
    N = box_num();

    for(int i=0;i<=N;i++) 
        bombs.push_back(i);

    box_report(getSecondMax(1,N));

}