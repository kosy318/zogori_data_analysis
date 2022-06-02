#include <bits/stdc++.h>
using namespace std;
int main() {
    int num;
    cin >> num;
    for(int i=0; i<5; i++){
        bool isOver = false;
        int pos_count = 0;
        int neg_count = 0;
        int pos[4] = {-1, -1, -1, -1};
        int neg[2][4] = {{-1, -1, -1, -1}, {-1, -1, -1, -1}};
        int input[2];
        cin >> input[1];
        if(input[1] < 0){
            neg_count++;
            neg[0][0] = neg[0][1] = 1;
            neg[0][2] = neg[0][3] = -input[1];
        }
        else if(input[1] != 1){
            pos_count++;
            pos[0] = pos[1] = 1;
            pos[2] = pos[3] = input[1];
        }

        for(int j=2; j<=num; j++){
            input[0] = input[1];
            cin >> input[1];
            if(input[1] < 0){
                if(input[0] == input[1]-1){neg[neg_count-1][1] = j;neg[neg_count-1][3] = -input[1];}
                else{
                    neg_count++;
                    if(neg_count >= 3){isOver = true;while(j++ < num){cin >> input[1];}break;}
                    if(pos_count == 1 && neg_count == 1 && pos[1] != j-1){isOver = true;while(j++ < num){cin >> input[1];}break;}
                    if(pos_count == 1 && neg_count == 2 && pos[0] < neg[0][0] &&neg[0][1] != j-1){isOver = true;while(j++ < num){cin >> input[1];}break;}
                    neg[neg_count-1][0] = neg[neg_count-1][1] = j;
                    neg[neg_count-1][2] = neg[neg_count-1][3] = -input[1];
                }
            }
            else if(input[1] != j){
                if(input[0] == input[1]-1){pos[1] = j;pos[3] = input[1];}
                else{
                    pos_count++;
                    if(pos_count >= 2){isOver = true;while(j++ < num){cin >> input[1];}break;}
                    if(neg_count == 1 && neg[0][1] != j-1){isOver = true;while(j++ < num){cin >> input[1];}break;}
                    if(neg_count == 2 && (neg[0][1] != neg[1][0]-1 || neg[1][1] != j-1)){isOver = true;while(j++ < num){cin >> input[1];}break;}
                    pos[0] = pos[1] = j;
                    pos[2] = pos[3] = input[1];
                }
            }
        }
        if(isOver){cout << "over\n";}
        else{
            if(pos_count == 0){
                if(neg_count == 0){cout << "two\n";}
                else if(neg_count == 1){cout << "one\n";}
                else if(neg_count == 2){cout << "two\n";}
            }
            else if(pos_count == 1){
                if(neg_count == 0){cout << "over\n";}
                else if(neg_count == 1){cout << "two\n";}
                else if(neg_count == 2){
                    if(pos[0] < neg[0][0] && pos[0] == neg[0][3] && pos[3] == neg[1][1]){cout << "two\n";}
                    else if(pos[0] > neg[1][0] && pos[1] == neg[1][2] && pos[2] == neg[0][0]){cout << "two\n";}
                    else if(neg[0][0] == neg[1][3] && neg[1][1] == neg[0][2]){cout << "two\n";}
                    else{cout << "over\n";}}}}}}
