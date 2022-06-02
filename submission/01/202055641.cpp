#include <iostream>
#include <string>
using namespace std;

int check(int, int);

string S;
int N;
int L = 0;
int flag = 0;
int tmp_l, tmp_r;

int main(void) {
    cin >> N;
    if( 3 <= N && N <= 10 ){
        for (int i = 0; i < N; ++i) {
            cin >> S;
            L=S.size();
            if( 3 <= L && L <= 100000 ){
             cout << check(0, S.size()-1) << endl;
            }
             else return -1;
        }
    }
    else return -1;
    return 0;
}

int check(int l, int r) {
    flag = 0;
    while (l < r) {
        if (S[l] == S[r]) {
            l++;
            r--;
            continue;
        }
        else {
            if(flag == 0 && S[l+1] == S[r]){
                tmp_l = l;
                tmp_r = r;
                l++;
                flag = 3;
                continue;
            }
            else if(flag == 0 && S[l] == S[r-1]){
                r--;
                flag = 1;
                continue;
            }
            else{
                if(flag == 3){
                    l=tmp_l;
                    r = tmp_r-1;
                    flag=1;
                }
                else{
                    flag = 2;
                    break;
                }
            }
        }
    }
    if(flag == 1 || flag == 3){
        return 2;
    }
    else if(flag == 2){
        return 3;
    }
    return 1;
}