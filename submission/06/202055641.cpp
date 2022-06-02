#include <iostream>
#include <string>
using namespace std;

string LPS(string s);
string MAX_S(string s,string t);
string DP[1000][1000];


int main(void){
    string S;
    string T;
    cin>>S;
    T=LPS(S);
    cout<<T<<endl;
}

string LPS(string s){
    int size=s.length();
    for(int i=0;i<size;i++){
        DP[i][i]=s.substr(i,1);
        if(i+1<size&&s[i]==s[i+1]){
            DP[i][i+1]=s.substr(i,2);
        }
        else if(i+1<size){
            DP[i][i+1]=MAX_S(s.substr(i,1),s.substr(i+1,1));
        }
    }
    int j=0;
    for(int g=3;g<=size;g++){
        for(int i=0;i<size-g+1;i++){
            j=i+g-1;
            if(s[i]==s[j]){
                DP[i][j]=DP[i][i]+DP[i+1][j-1]+DP[j][j];
            }
            else{
                DP[i][j]=MAX_S(DP[i+1][j],DP[i][j-1]);
            }
        }
    }
    return DP[0][size-1];
}

string MAX_S(string s,string t){
    if(s.length()>t.length()){
        return s;
    }
    else if(s.length()<t.length()){
        return t;
    }
    else{
        int i=s.compare(t);
        if(i<0) return s;
        else if(i>0) return t;
        else return s;
    }
}