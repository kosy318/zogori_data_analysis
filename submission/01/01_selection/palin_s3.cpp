#include <iostream>
#include <string>
#include <list>

using namespace std;

int palindrome(string str){
    int ret, start, end;
    ret = 1;
    start = 0;
    end = str.size()-1;

    while (start <= end){
        if (str[start] == str[end]) { start++; end--; }
        else {
            int s, e;
            
            int check1 = 1;
            s = start+1;
            e = end;
            while (s <= e){
                if (str[s] != str[e]) {
                    check1 = 0;
                    break;
                }
                s++; e--;
            }

            int check2 = 1;
            s = start;
            e = end-1;
            while (s <= e) {
                if (str[s] != str[e]) {
                    check2 = 0;
                    break;
                }
                s++; e--;
            }

            if (check1 == 0 && check2 == 0) ret = 3;
            else ret = 2;
            return ret;
        }
    }
    return ret;
}

int main(){
    int n;
    list<string> strs;
    string str;

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> str;
        strs.push_back(str);
    }

    list<string>::iterator iter = strs.begin();
    for (iter=strs.begin(); iter!=strs.end(); iter++){
        cout << palindrome(*iter) << endl;
    }

    return 0;
}