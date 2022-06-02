#include <iostream>
#include <string>

using namespace std;

int N; //test case 개수, 5<= N <=20

int check_backspace(string str1, string str2, int beforp, int p);

int main()
{
   cin>> N;

   string s, t;//5<= s <=10,000
   int check = 2;

   for(int i=0; i<N; i++){
        cin>> s;
        cin>> t;

        if(s.length() > t.length()){
            for(int j=0; j<s.length(); j++){
                if(s.find(t[0])!= string::npos){
                        if(t.length() == 1){
                            check = 1;
                            break;
                        }
                        check = check_backspace(s, t, s.find(t[0])+1, 1);
                        if(check == 1){
                            break;
                        }
                }
                s = s.substr(s.find(t[0])+1);
            }
            if(check == 1){
                        cout<< "YES" <<endl;
            }
            else{
                        cout<< "NO" <<endl;
            }

        }
        else if(s.length() == t.length()){
            if(s == t){
                cout<< "YES" <<endl;
            }
            else{
                cout<< "NO" <<endl;
            }
        }
        else {
            cout<< "NO" <<endl;
        }
   }

    return 0;
}

int check_backspace(string str1, string str2, int beforep, int p){
    int str1l = str1.length();
    int str2l = str2.length();
    int check = 2;


    for(int i=0; i<str1l; i++){
        int gap = i*2;
        if(str1[beforep+gap] == str2[p]){


             if(p == str2l-1){
                    if((str1l-1-(gap+beforep))%2 == 0){
                        return 1;
                    }
                    else {
                        return 2;
                    }
             }

            check = check_backspace(str1, str2, beforep+gap+1, p+1);
            if(check == 1){
                return 1;
            }
        }
    }

    return 2;


}
