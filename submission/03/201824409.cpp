#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10001
using namespace std;

int fish[MAX] ={0};
int fish_copy[MAX] = {0};
int n;

int check(int array[]){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(abs(array[i]) != i) return 100;
        else if(abs(array[i]) == i and array[i] < 0) count++;
    }
    return count;
}

void flip(int array[],int L, int R){
    if(L == R) array[L] = -array[L];
    if(L < R){
        array[L] = -array[L];
        array[R] = -array[R];
        swap(array[L], array[R]);
        flip(array,L+1, R-1);
    }
}

int main() {
    cin >> n;
    int Left = -1, Right = -1;
    int count = 0, back_count = 0;
    for(int i = 0; i < 5; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> fish[j];
            fish_copy[j] = fish[j];
        }

        for (int k = 1; k <= n; k++) {
            if (abs(fish[k]) != k and Left == -1) {
                Left = k;
                continue;
            }
            else if (abs(fish[k]) == Left and Left != -1) {
                Right = k;
                count++;
                flip(fish, Left, Right);
                Left = -1;
                Right = -1;
                k = 1;
            }
        }
        Left = -1, Right = -1;
        if(count + check(fish) > 2){
            for (int x = n; x > 0; x--) {
                if (abs(fish_copy[x]) != x and Right == -1) {
                    Right = x;
                    continue;
                } else if (abs(fish_copy[x]) == Right and Right != -1) {
                    Left = x;
                    back_count++;
                    flip(fish_copy, Left, Right);
                    Left = -1;
                    Right = -1;
                    x = n;
                }
            }
        }

        if(count + check(fish) == 1 or back_count + check(fish_copy) == 1) cout << "one" << endl;
        else if(count + check(fish) == 2 or back_count + check(fish_copy) == 2) cout << "two" << endl;
        else cout << "over" << endl;
        count = 0, back_count = 0, Left = -1, Right = -1;
    }
}