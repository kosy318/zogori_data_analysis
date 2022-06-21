#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int N;
int Num[MAX]; // 입력받을 배열
int Num1[MAX];

void reverse(int* num,int left, int right)
{
    if(left < right)
    {
        swap(num[left],num[right]);
        reverse(num,left+1,right-1);
    }
}

bool Check(const int* num){
    for(int i = 1; i <= N; i++){
        if(i != num[i]) return false;
    }
    return true;
}

void Func(){
    int start = -10003;
    int end   = -10003;
    int count = 0;

    for(int i = 1; i <= N; i++) {
        if (i != Num[i] && start == -10003) start = i;
        if (start == abs(Num[i])) {
            end = i;

            reverse(Num,start,end);
            for (int j = start; j <= end; j++) Num[j] = -Num[j];

            if(Check(Num)) break;
            else{
                count++;
                i = 1;
                start = -10003;
                end   = -10003;
            }
            if(count == 2) break;
        }
    }
    if(count == 0) cout << "one" << endl;
    else if(count == 1) cout << "two" << endl;
    else{
        for(int i = N; i > 0; i--) {
            if (i != Num1[i] && end == -10003) end = i;
            if (end == abs(Num1[i])) {
                start = i;

                reverse(Num1,start,end);
                for (int j = start; j <= end; j++) Num1[j] = -Num1[j];

                if(Check(Num1)) break;
                else{
                    count++;
                    i = N;
                    start = -10003;
                    end   = -10003;
                }
                if(count == 4) break;
            }
        }
        if(count == 2) cout << "one" << endl;
        else if(count == 3) cout << "two" << endl;
        else cout << "over" << endl;
    }
}



void Fishbread(){
    cin >> N;
    for(int j = 0; j < 5; j++){
        for(int i = 1; i <= N; i++){
            cin >> Num[i];
            Num1[i] = Num[i];
        }
        Func();
    }
}

int main() {
    Fishbread();
    return 0;
}