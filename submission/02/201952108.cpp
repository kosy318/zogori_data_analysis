#include <iostream>
#include <string>
using namespace std;

void inputData();
bool backspace(string s, string t);
bool check(string s, string t, int sI, int tI);

int main(){
    inputData();
}

void inputData(){
    int n;
    string s, t;
    cin >> n;
    
    while(n-- > 0){
        cin >> s >> t;
        bool ok = backspace(s, t);
        if (ok == true) cout << "YES" << endl;
        else            cout << "NO"  << endl;
    }
}

bool backspace(string s, string t){
    bool ret;
    if (s.size() < t.size()) return false;
    else if (s.size() == t.size() && s != t) return false;
    else if (s == t) return true;
    else{
        for (int i = 0; i < s.size(); i++){
            if (s[i] == t[0]) {
                if (t.size() == 1) return true;
                ret = check(s, t, i, 1);
                if (ret == true) break;
            }
        }
    }
    return ret;
}

bool check(string s, string t, int sI, int tI){
    for (int i = sI + 1; i < s.size(); i += 2){
        if(s[i] == t[tI]) {
            if ((tI == t.size() - 1) && ((s.size() - i) % 2 == 1)) {
                return true;
            }
            return check(s, t, i, ++tI); //return 필요
        }
    }
    return false;
}