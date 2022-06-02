#include <iostream>
#include <vector>
#include <string>

using namespace std;

string palindrome;

int p(int l, int r, int res) {
//    cout << l << " " << r << " " << res << " " << endl;
    
    if(l >= r)
        return res;
    
    if(palindrome[l] != palindrome[r]) {
        if(res == 1)
            return min(p(l + 1, r, 2), p(l, r - 1, 2));
        else
            return 3;
    } else
        return p(l + 1, r - 1, res);
    
    return res;
}

int main() {
    int T;
    
    cin >> T;
    
    for(int q = 0; q < T; q++) {
        cin >> palindrome;
        
        int l = 0;
        int r = (int)palindrome.length() - 1;
        
        cout << p(l, r, 1) << endl;
    }
    
    return 0;
}
