#include <iostream>
using namespace std;

int Ispalindrome(int L, int R, int check, string str){
    while(L < R){
        if(str[L] != str[R]){
            if(check == 0){
                if(Ispalindrome(L+1, R, 1, str) == 1 or Ispalindrome(L, R-1, 1, str) == 1) return 2;
                return 3;
            }
            else return 3;
        }
        else{
            L++;
            R--;
        }
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        cout << Ispalindrome(0, str.length()-1, 0, str) << endl;
    }
}
