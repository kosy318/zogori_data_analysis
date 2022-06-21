#include <bits/stdc++.h>
using namespace std;
int N;
int countFlip(vector<int> arr, int start);
void flip(vector<int> &arr, int i, int j, int &cnt);
auto isIn = [](int i){return i<=N && i>=0;};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<int> arr(N+1);
    for(int i=0;i<5;i++) {
        for(int j=1;j<=N;j++) cin >> arr[j];
        switch(min(countFlip(arr, 0), countFlip(arr, N))){
            case 1 : cout << "one\n"; break;
            case 2 : cout << "two\n"; break;
            default: cout << "over\n";
        }
    }
}

int countFlip(vector<int> arr, int start) {
    int cnt = 0, direction = start ? -1 : 1;
    for(int i=start; isIn(i); i+=direction) {
        for(int j=i; isIn(j); j+=direction)
            if(arr[i]==i) break;
            else if(abs(arr[j])==i) {
                flip(arr, i, j, cnt);
                if(arr[i] < 0) flip(arr, i, i, cnt);
            }
        if(cnt > 2) return 3;
    }
    return cnt;
}

void flip(vector<int> &arr, int i, int j, int &cnt) {
    int from = min(i,j), to = max(i,j);
    reverse(arr.begin()+from, arr.begin()+(to+1));
    for(int i=from;i<=to;i++) arr[i] *= -1;
    cnt++;
}