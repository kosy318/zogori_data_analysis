#include <bits/stdc++.h>
using namespace std;
int getCode(string& target);
bool isQuasiPalindrome(string& target, int begin, int end);

int main() {
    int num;
    cin >> num;
    for(int i=0; i<num; i++){
        string target;
        cin >> target;
        cout << getCode(target) << endl;
    }
}

int getCode(string& target){
    int i = 0;
    int len = target.length();
    while(i < len-1-i){
        if(target[i] != target[len-1-i]){
            if(isQuasiPalindrome(target, i, len-2-i) || isQuasiPalindrome(target, i+1, len-1-i)){
                return 2;
            }
            else{
                return 3;
            }
        }
        i++;
    }
    return 1;
}

bool isQuasiPalindrome(string& target, int begin, int end){
    while(begin < end){
        if(target[begin] != target[end]){return false;}
        begin++;
        end--;
    }
    return true;
}
