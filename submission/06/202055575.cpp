#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> table;

void set_table(int size){
    table.resize(size);
    for(vector<string>& i : table){
        i.resize(size,"");
    }
}

string max(string x, string y){
    if(x.size() == y.size()){
        if(x < y) return x;
        else return y; } 
    else if(x.size()>y.size()) return x;
    else return y;
}

string code(string str, int st, int end){
    if(!table[st][end].empty()) return table[st][end];
    int size = end - st + 1;

    if(size <= 3 && str[st]==str[end]) {
        table[st][end] = str.substr(st,size); 
        return table[st][end];}

    else if(size == 2) {
        table[st][end] = max(str.substr(st,1),str.substr(end,1));
        return table[st][end];}

    if(str[st] == str[end])
        table[st][end] = str[st] + code(str,st+1,end-1) + str[end];
    else
        table[st][end] = max(code(str,st,end-1),code(str,st+1,end));

    return table[st][end];
}

int main(){
    string str;
    cin >> str;

    set_table(str.size());
    code(str,0,str.size()-1);
    cout << table[0][str.size()-1];
}