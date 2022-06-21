#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
string S;

int Is_palindrome(string s){
    int count = 0;
    int idx1,idx2;
    for(int i = 0, j = s.length()-1; i < j; i++, j--){
        if(s[i] != s[j]){    // 일치하지 않은 첫 위치를 발견
            idx1 = i;
            idx2 = j;
            count++;
            break;
        }
    }
    if(count == 0) return 1;   // 회문
    else{                      // count = 1
        int check1 = 0;
        int check2 = 0;
        string s1 = s;
        string s2 = s;
        s1.erase(idx1,1);  // 앞 문자 제거
        s2.erase(idx2,1);  // 뒷 문자 제거

        for(int i = 0, j = s1.length()-1; i < j; i++, j--){
            if(s1[i] != s1[j]) check1 = 1;
            if(s2[i] != s2[j]) check2 = 1;
        }
        if(check1 + check2 == 2) return 3;
        else return 2;
    }
}


void Solve(){
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> S;
        cout << Is_palindrome(S) << endl;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}