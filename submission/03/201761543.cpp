#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, answer;

bool isOne(vector<int> v) {
    vector<int> one;
    int cnt = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i] > 0) {
            if(v[i] == i+1) continue;
            cnt++;
        }
        else {
            if(one.empty() || one.back() + 1 != v[i]) {
                cnt++;
                one.push_back(v[i]);
            }
            else if(one.back() + 1 == v[i]) one.push_back(v[i]);
        }
    }
    return (cnt <= 1);
}

bool isTwo(vector<int> v) {
    for(int i=0; i<v.size(); i++) {
        if(v[i] == i+1) continue;
        int mini, maxi;
        if(i < abs(v[i])) mini = i, maxi = abs(v[i]);
        else mini = abs(v[i])-1, maxi = i+1;
        
        reverse(v.begin()+mini, v.begin() + maxi);
        for(int j=mini; j<maxi; j++) v[j] = -v[j];
        if(isOne(v)) return true;
        reverse(v.begin()+mini, v.begin() + maxi);
        for(int j=mini; j<maxi; j++) v[j] = -v[j];
    }
    return false;
}

void init() {
    cin >> n;
    for(int i=0; i<5; i++) {
        vector<int> v;
        int answer = 0;
        for(int j=1; j<=n; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        if(isOne(v)) cout << "one" << '\n';
        else if(isTwo(v)) cout << "two" << '\n';
        else cout << "over" << '\n';
    }
}																		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}