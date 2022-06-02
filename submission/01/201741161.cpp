#include<bits/stdc++.h>
#define MAX 100002
using namespace std;
int N;
string inp;
enum { PALIN = 1, SEMI_PALIN, NOT_PALIN };
int isPalin(string &s, int left, int right, int del){
    while(left < right){
        if(s[left] != s[right]){
            if(del==0){
                if(isPalin(s, left+1, right, 1) == 1 || isPalin(s, left, right-1, 1)==1)
                    return SEMI_PALIN;
                return NOT_PALIN;
            }
            else return NOT_PALIN;
        }
        else{
            left++;
            right--;
        }
    }
    return PALIN;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while(N--){
        cin >> inp;
        cout << isPalin(inp, 0, inp.length()-1, 0) << '\n';
    }
}