#include <iostream>
#include <string>
using namespace std;

int checkPalin(string str, int cnt){
    int i=0, len = str.size();
    for(; i < len/2; i++){
        if(str[i] != str[len-i-1]){
            if(cnt == 1) return 3;

            string tmp1 = str;
            tmp1.replace(i, 1, "");
            int result1 = checkPalin(tmp1, cnt+1);
            if(result1 == 1) return 2;

            string tmp2 = str;
            tmp2.replace(len-i-1, 1, "");
            int result2 = checkPalin(tmp2, cnt+1);
            if(result2 == 1) return 2;
            else return 3;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    string tmp;

    for(int i=0; i<T; i++){
        cin >> tmp;
        cout << checkPalin(tmp, 0) << "\n";
    }
}
