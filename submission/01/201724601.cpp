#include <iostream>
#include <string>

using namespace std;

int N;

int getAns(string str);
bool isPalin(string str, int size);
bool psePalin(string str, int size, int N);

int main(void){
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        string str;
        cin >> str;
        cout << getAns(str) << endl;
    }

    return 0;
}

int getAns(string str){
    int size = str.size();
    if(isPalin(str, size)){
        return 1;
    }else if(psePalin(str, size, N)){
        return 2;
    }else{
        return 3;
    }
}

bool isPalin(string str, int size){
    for(int i = 0; i < size; i++){
        if(str[i] != str[size-i-1]){
            N = i;
            return false;
        }else if(i >= size-i-1){
            return true;
        }
    }
}

bool psePalin(string str, int size, int N){
    int rsize = size-2*N-1;
    if(str[N] == str[size-N-2]){
        return isPalin(str.substr(N,rsize), rsize);
    }else if(str[N+1] == str[size-N-1]){
        return isPalin(str.substr(N+1, rsize), rsize);
    }else{
        return false;
    }
}
