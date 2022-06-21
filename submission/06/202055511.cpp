#include <bits/stdc++.h>
using namespace std;
string table[1000][1000];
int main() {
    string text;
    cin >> text;
    int len = text.length();
    
    for(int i=0; i<len-1; i++) {
        table[i][i] = text[i];
        table[i + 1][i] = "";
    }
    table[len-1][len-1] = text[len-1];

    for(int j=1; j<len; j++){
        for(int i=0; i+j<len; i++){
            if(make_tuple(-(table[i][i+j-1].length()), table[i][i+j-1]) < make_tuple(-(table[i+1][i+j].length()), table[i+1][i+j])){
                table[i][i+j] = table[i][i+j-1];
            }
            else{
                table[i][i+j] = table[i+1][i+j];
            }
            
            if(text[i] == text[i+j]){
                string temp = text[i] + table[i+1][i+j-1] + text[i+j];
                if(make_tuple(-(temp.length()), temp) < make_tuple(-(table[i][i+j].length()), table[i][i+j])){
                    table[i][i+j] = temp;
                }
            }
        }
    }
    cout << table[0][len-1];
}
