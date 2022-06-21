#include <bits/stdc++.h>
using namespace std;
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int len1 = str1.length();
    int len2 = str2.length();
    string max = "";
    pair<string, bool> table[len1][len2];
    if(str1[0] == str2[0]){
        table[0][0] = make_pair(str1[0], true);
        max = str1[0];
    }
    else{table[0][0] = make_pair("",false);}
    for(int j=1; j<len2; j++){
        if(str1[0] == str2[j]){
            table[0][j] = make_pair(str1[0],true);
            if(make_pair(-int(max.length()), max) > make_pair(-int(table[0][j].first.length()), table[0][j].first)){max = table[0][j].first;}
        }
        else{
            if(table[0][j-1].second){
                table[0][j] = make_pair(str1[0], false);
            }
            else{
                table[0][j] = make_pair("", false);
            }
        }
    }
    for(int i=1; i<len1; i++){
        if(str2[0] == str1[i]){
            table[i][0] = make_pair(str2[0],true);
            if(make_pair(-int(max.length()), max) > make_pair(-int(table[i][0].first.length()), table[i][0].first)){max = table[i][0].first;}
        }
        else{
            if(table[i-1][0].second){
                table[i][0] = make_pair(str2[0], false);
            }
            else{
                table[i][0] = make_pair("", false);
            }
        }
    }
    for(int i=1; i<len1; i++){
        for(int j=1; j<len2; j++){
            if(str1[i] == str2[j]){
                table[i][j] = make_pair(table[i-1][j-1].first + str1[i], true);
                if(make_pair(-int(max.length()), max) > make_pair(-int(table[i][j].first.length()), table[i][j].first)){
                    max = table[i][j].first;
                }
            }
            else{
                string temp = "";
                if(table[i-1][j-1].second && make_pair(-int(temp.length()), temp) > make_pair(-int(table[i-1][j-1].first.length()), table[i-1][j-1].first)){
                    temp = table[i-1][j-1].first;
                }
                if(table[i][j-1].second && make_pair(-int(temp.length()), temp) > make_pair(-int(table[i][j-1].first.length()), table[i][j-1].first)){
                    temp = table[i][j-1].first;}
                if(table[i-1][j].second && make_pair(-int(temp.length()), temp) > make_pair(-int(table[i-1][j].first.length()), table[i-1][j].first)){
                    temp = table[i-1][j].first;
                }
                table[i][j] = make_pair(temp, false);
            }
        }
    }/*
    for(int i=0; i<len1; i++){
        for(int j=0; j<len2; j++){
            cout << table[i][j].first << " | ";
        }
        cout <<endl;
    }*/
    cout << max;
}
