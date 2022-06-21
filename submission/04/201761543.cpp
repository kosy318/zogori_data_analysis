#include <bits/stdc++.h>
#include "timebomb.h"
using namespace std;
typedef pair<int, int> pii;
int arr[5010];

int len, heapIdx = 0;

void push(int boxIdx) {
    int idx = ++heapIdx;
    arr[idx] = boxIdx;
    while((idx != 1) && (box_comp(boxIdx, arr[idx/2])) == 1) {
        swap(arr[idx/2], arr[idx]);
        idx /= 2;
    }    
}

int main() {    
    memset(arr, 0, sizeof(arr));
    box_ready();
    len = box_size();
    for(int i=1; i<=len; i++) push(i);    
    int result = box_comp(arr[2], arr[3]);
    if(result == 1) box_report(arr[2]);
    else box_report(arr[3]);
    
}