#include <bits/stdc++.h>

using namespace std;

int N, ans;
string data;

bool palin(string::iterator left, string::iterator right, int pln){

    while(left - right < 0 && pln < 3){
        if(*left == *right){
            left ++;
            right--;
        }
        else{
            pln++;
            if(palin(left+1, right, pln) || palin(left, right-1, pln)) ans = 2;
            else                                                       ans = 3;

            return pln<3;
        }
    }

    ans = 1;

    return pln < 3;
}

int main()
{


    cin >> N;


    for(int i = 0; i<N; i++){
        cin >> data;
        palin(data.begin(), data.end()-1, 1);
        cout << ans << "\n";
    }



    return 0;
}
