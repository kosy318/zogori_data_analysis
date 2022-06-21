#include "bits/stdc++.h"
using namespace std;

string S,T;

void Input(){
    cin >> T >> S;
}

int Table(vector<vector<int>> &table){

    int a,b,c,d;
    int table_max =0;
    for(int i = 2; i < S.length() + 2; i++){
        for(int j = 2; j < T.length() + 2; j++){
            if(S[i-2]==T[j-2]) {
                a = table[i-2][j-2];
                b = table[i-2][j-1];
                c = table[i-1][j-2];
                d = table[i-1][j-1];
                table[i][j] = max({a,b,c,d})+1;
                if(table_max < table[i][j]) table_max = table[i][j];
            }
        }
    }
    return table_max;
}
string Move(int i, int j, int n, vector<vector<int>> table,string &str){
    int a,b,c,d;

    string str_a="~";
    string str_b="~";
    string str_c="~";
    string str_d="~";

    a = table[i-2][j-2];
    b = table[i-2][j-1];
    c = table[i-1][j-2];
    d = table[i-1][j-1];

    str=S[i-2]+str;

    string temp =str;

    if(n == 1) {
        return str;
    }

    if(a == n-1){
        str_a ="";
        str = temp;
        str_a = Move(i-2,j-2,n-1,table,str);
    }
    if(b == n-1){
        str_b ="";
        str = temp;
        str_b = Move(i-2,j-1,n-1,table,str);
    }
    if(c == n-1){
        str_c ="";
        str = temp;
        str_c = Move(i-1,j-2,n-1,table,str);
    }
    if(d == n-1){
        str_d ="";
        str = temp;
        str_d = Move(i-1,j-1,n-1,table,str);
    }
    str = min({str_a,str_b,str_c,str_d});

    return str;

}

string Find_quasi(vector<vector<int>> table, int table_max){
    string result="~";
    string temp = "";

    for(int i = table_max + 1; i< S.length() + 2; i++){
        for(int j = table_max + 1; j<T.length() + 2; j++){
            if(table[i][j] == table_max){
                temp = "";
                temp = Move(i,j,table_max,table,temp);
                if (result > temp) result = temp;
            }
        }
    }
    return result;
}

int main() {
    Input();
    vector<vector<int>> table(S.length()+2, vector<int>(T.length()+2,0));

    int table_max = Table(table);

    cout << Find_quasi(table,table_max)<<endl;

    return 0;
}

