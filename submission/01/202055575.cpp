#include <bits/stdc++.h>

using namespace std;

bool is_palin(string str){
    string::iterator st = str.begin();
    string::iterator bk = --str.end();
    while(st!=bk){
        if(*st!=*bk) return false;
        if(++st == bk--) break;
    }
    return true;
}

bool is_qpalin(string str){
    for(int i=0; i!=str.size()-1; i++){
        string t_str(str);
        if(is_palin(t_str.erase(i,1))) return true;
    }
    return false;
}

int decide_val(string str){
    if(is_palin(str)) return 1;
    if(is_qpalin(str)) return 2;
    else return 3;
}

void exec(){
    int input; cin >> input;
    for(int i=0; i<input; i++){
        string str; cin >> str;
        cout << decide_val(str) << endl;
    }
}

int main(){
    exec();
    return 0;
}