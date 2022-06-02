#include <bits/stdc++.h>

#define MAX_VAL 9223372036854775800
#define MIN_VAL -9223372036854775800

using namespace std;

typedef long long int ll;

vector<string> tokens;
vector<int> nums;
vector<string> operators;
vector<vector<pair<ll,ll>>> table;

vector<string> opers = {"+","-","*"};
int loop(string op){
    for(int i=0;i<opers.size();i++) if(op == opers[i]) return i; 
}

ll operation(ll a,ll b, int op){
    switch(op){
        case 0 : return a+b;
        case 1 : return a-b;
        case 2 : return a*b;
    }
    return 0;
}

void print_table(){
    for(auto i: table){
        for(auto j : i){
            printf(" %4d %4d |",j.first,j.second);
        }
        cout << "\n";
    }
}

void input(){
    string s;
    getline(cin,s); s+='\n';
    int j = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]==' ' || s[i]=='\n') {
            tokens.push_back(s.substr(j,i-j));
            j=i+1;
        } 
    }
}

void set_table(){
    for(int i=0; i<tokens.size(); i+=2){
        nums.push_back(stoi(tokens[i]));
        if(i<tokens.size()-1)
            operators.push_back(tokens[i+1]);
    }
    table.resize(nums.size(),vector<pair<ll,ll>>
    (nums.size(),make_pair(NULL,NULL)));

}

pair<ll,ll>& dp(int i, int j){

    if(table[i][j].first != NULL && table[i][j].second != NULL) 
        return (table[i][j]);

    pair<ll,ll> p(MIN_VAL, MAX_VAL);
    if(i==j) {
        p.first = nums[i]; p.second = nums[j];
    }
    else{
        for(int k=0;k!=i-j;k++){
            pair<ll,ll> p1 = dp(j+k, j);
            pair<ll,ll> p2 = dp(i, j+k+1);
            ll ma;ll mi; string op = operators[j+k];
            int iop = loop(op);

            ll op1 = operation(p1.first, p2.first, iop);
            ll op2 = operation(p1.first, p2.second, iop);
            ll op3 = operation(p1.second, p2.first, iop);
            ll op4 = operation(p1.second, p2.second, iop);

            ma = max({op1,op2,op3,op4});
            mi = min({op1,op2,op3,op4});
        
            if(ma > p.first)  p.first = ma;
            if(mi < p.second)  p.second = mi;
        }
    }
    table[i][j] = p;
    return table[i][j];
}


int main(){
    input();
    set_table();
    cout << dp(nums.size()-1,0).first << "\n";
    //print_table();
}