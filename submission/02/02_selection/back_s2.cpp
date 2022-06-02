#include <bits/stdc++.h>
using namespace std;
int N; string str1, str2;

bool check(int idx1, int idx2) {
    if(idx2 >= (int)str2.size()) return (str1.size()-idx1-1) % 2 ? 0 : 1;
    
    for(int i=idx1+1;i<str1.size();i++)
        if((idx1>=0 && (i-idx1) % 2 || idx1<0) 
        && str2[idx2] == str1[i] && check(i, idx2+1)) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> N;
    while(cin >> str1 >> str2)
        if(check(-1, 0)) cout << "YES\n"; else cout << "NO\n";
}