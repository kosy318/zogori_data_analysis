#include<iostream>
#include<string>
#include<cstring>

using namespace std;

bool PalinOrNotpalin(string str){ //회문인지 아닌지 여부 반환
    for(int i=0;i<str.length()/2;i++){
        if(str[i]!=str[str.length()-1-i]){
            return false;   //회문이 아니다
        }
    }
    return true;  //회문이다
}

int isPalindrome(string str){
    //cout<<str.length()<<endl;
    for(int i=0;i<str.length()/2;i++){
        if(str[i]!=str[str.length()-1-i]){
            string newStr1=str.substr(0,i)+str.substr(i+1,str.length()-1);
            string newStr2=str.substr(0,str.length()-1-i)+str.substr(str.length()-i,str.length()-1);
            if(PalinOrNotpalin(newStr1)||PalinOrNotpalin(newStr2)){
                return 2;
            }
            return 3;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L;
    cin>>L;
    string str;
    for(int i=0;i<L;i++){
        cin>>str;
        cout<<isPalindrome(str)<<endl;
    }

    return 0;
}