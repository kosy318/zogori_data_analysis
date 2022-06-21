#include <iostream>
using namespace std;

string dp[103][103];
string S, T;

string compare(string a, string b){
    if(a.size() == b.size()){
        return min(a, b);
    } else if(a.size() > b.size()){
        return a;
    } else {
        return b;
    }
}

void quasi(){
    int i,j;

    string maxString = "";

    for(i=2; i<T.size()+2; i++){
        for(j=2; j<S.size()+2; j++){
            if(S[j-2] == T[i-2]){
                string tmp1 = compare(dp[i-2][j-2],dp[i-2][j-1]);
                string tmp2 = compare(dp[i-1][j-2],dp[i-1][j-1]);
                dp[i][j] = compare(tmp1, tmp2) + S[j-2];
                maxString = compare(maxString, dp[i][j]);
            } else {
                dp[i][j] = "";
            }
        }
    }

    cout << maxString;
}

void init(){
    cin >> S >> T;

    int i,j;
    for(i=0; i<S.size(); i++)
        for(j=0; j<2; j++)
            dp[i][j] = "";

    for(i=0; i<2; i++)
        for(j=0; j<T.size(); j++)
            dp[i][j] = "";
}

int main(){
    init();
    quasi();
    return 0;
}
