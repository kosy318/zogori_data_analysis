#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s, t;

bool f(int sIndex, int tIndex) {
    if(sIndex >= s.size())
        return false;
    
    if(tIndex == t.size() - 1 && (s.size() - 1 - sIndex) % 2 == 0 && s[sIndex] == t[tIndex])
        return true;
    
    int step = tIndex == 0 ? 1 : 2;
    
    if(s[sIndex] != t[tIndex])
        return f(sIndex + step, tIndex);
    
    return f(sIndex + 1, tIndex + 1) || f(sIndex + step, tIndex);
}

int main() {
    int N;
    
    cin >> N;
    
    for(int q = 0; q < N; q++) {
        cin >> s >> t;
        
        if(f(0, 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
