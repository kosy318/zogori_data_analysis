#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vc;

void make_vc(string s,char t_char,int n){
    
    for(int i=0; i<s.size(); i++){
        if(s[i]==t_char) vc[n].push_back(i); 
    }
}

bool result;

void func(int n, int last, string s){
    
    if(n >= vc.size()) {
        if((s.size()-last) % 2 == 1) result = true; 
        return;
    } 
    for(int i=0; i<vc[n].size(); i++){
        if(vc[n][i]<=last && n != 0) continue;
        if((vc[n][i]-last) % 2 == 1 || n==0) func(n+1,vc[n][i],s);
    }
}

bool decide(string s, string t){
    int n=0;
    for(int i=0; i<t.size(); i++){
        make_vc(s,t[i],n++);
    }
    result = false;
    func(0,0,s);
    return result;
}

void exec(){
    int input; cin>>input;
    while(input--){
        string s; cin >> s;
        string t; cin >> t;
        vc.clear(); vc.resize(t.size());
        if(decide(s,t)) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
}

int main(){
    exec();
    return 0;
}