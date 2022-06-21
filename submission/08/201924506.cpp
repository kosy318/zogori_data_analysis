#include <iostream>
#include <string>

using namespace std;

string compare(string a, string b) {
    if(a.length() > b.length())
        return a;
    
    if(a.length() < b.length())    
        return b;
    
    if(a < b)
        return a;
    
    return b;
}

int main()
{
    string a, b, res;
    string dp[110][110];
    
    cin >> a >> b;
    
    a = "  " + a;
    b = "  " + b;
    
    for(int i = 2; i < a.length(); i++) {
        for(int j = 2; j < b.length(); j++) {
            if(a[i] == b[j]) {
                dp[i][j] = compare(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = compare(dp[i][j], dp[i - 2][j - 1]);
                dp[i][j] = compare(dp[i][j], dp[i - 1][j - 2]);
                dp[i][j] = compare(dp[i][j], dp[i - 2][j - 2]);
                
                dp[i][j] = dp[i][j] + a[i];
                
                res = compare(res, dp[i][j]);
            }
        }
    }

    cout << res;

    return 0;
}
