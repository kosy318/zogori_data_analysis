#include "timebomb.h"

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> last_comp;

int find_max(vector<int> arr, int Size) {
    vector<int> new_Arr;
    if(Size == 1) return arr[0];
    for(int i = 0; i < Size; i+=2) {
        if (i == Size-1) { 
            new_Arr.push_back(arr[i]);
            break;
        }
        int comp = box_comp(arr[i],arr[i+1]);
        if (comp == 1) {
            new_Arr.push_back(arr[i]);
            last_comp[arr[i]].push_back(arr[i+1]);
        } else {
            new_Arr.push_back(arr[i+1]);
            last_comp[arr[i+1]].push_back(arr[i]);
        }
    }
    return find_max(new_Arr, new_Arr.size());
}



int main() {
    box_ready() ;
    int N = box_size();
    last_comp.resize(N+1);
    vector<int>first_arr(N);
    for (int i = 1; i <= N; i++) first_arr[i-1] = i;



    int best = find_max(first_arr, N);
    int two_best = find_max(last_comp[best], last_comp[best].size());
    box_report(two_best);
}