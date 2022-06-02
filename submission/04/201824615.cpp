#include <bits/stdc++.h>
#include "timebomb.h"
using namespace std;

int main() {
    box_ready();
    int N = box_size();
    vector<int> arr(N);
    map<int, vector<int>> m;
    iota(arr.begin(), arr.end(), 1);

    while(arr.size() > 1) {
        vector<int> tmp;
        for(int i=0;i<arr.size();i+=2)
            if(i==arr.size()-1) tmp.push_back(arr[i]);
            else {
                int result = box_comp(arr[i], arr[i+1]), 
                big   = result>0 ? arr[i] : arr[i+1],
                sml = result<0 ? arr[i] : arr[i+1];

                if(m[big].size()) m[big].push_back(sml);
                else m[big] = vector<int>{sml};
                tmp.push_back(big);
            }
        arr.swap(tmp);
    }
    auto &seconds = m[arr[0]];
    
    int ans = seconds[0];
    for(auto &w : seconds) 
        if(box_comp(w, ans) > 0) ans = w;
    
    box_report(ans);
}