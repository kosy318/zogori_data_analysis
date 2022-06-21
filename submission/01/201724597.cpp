#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int quasi_palindrome_check(string str3, string str4, int j);

int N; //문자열의 개수
int L; //문자열의 길이, 3<= L <=100,000

int main()
{
    string str1; //문자열
    string str2; //문자열 반전
    int result1;
    int result2;

    cin>> N; // 3<= N <=10


    for(int i=0; i<N; i++){
        cin>> str1;
        L = str1.length();
        str2.resize(str1.size());
        copy(str1.rbegin(), str1.rend(), str2.begin());
        //cout<<str2<<endl;
        if(str1 == str2){
            cout<< 1 <<endl;
        }
        else{
            for(int k=0; k<L; k++){
                if(str1[k] != str2[k]){
                    result1 = quasi_palindrome_check(str1, str2, k);
                    result2 = quasi_palindrome_check(str1, str2, L-k-1);
                }
            }
            if(result1 == 2 || result2 == 2){
                cout<< 2 <<endl;
            }
            else {
                cout<< 3 <<endl;
            }
        }

    }
    return 0;
}


int quasi_palindrome_check(string str3, string str4, int j){
    str3.erase(str3.begin() + j);
    str4.erase(str4.end() - j -1);
    //cout<< str3 <<endl;
    //cout<< str4 <<endl;
    if(str3 == str4){
        return 2;
    }
    else{
        return 3;
    }
}
