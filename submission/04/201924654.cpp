#include "timebomb.h"
#include <math.h>

int tree[16385];
int arr[15];

int main(){
    int N, result, max_index, i, a, cmp;
    int tree_size, tmp, last;

    box_ready();
    N = box_size();

    tree_size = 1;
    tmp = 1;

    while(N > tmp){
        tmp *= 2;
        tree_size += tmp;
    }

    last = tree_size;

    for(int j=0; j<N; j++){
        tree[last-j] = j+1;
    }

    while(tmp!=1){
        i=last+2;

        for(int j=0; j<tmp/2; j++){
            i -=2;

            if(tree[i-1]==0 || tree[i]==0){
                if(tree[i]!=0){
                    tree[i/2] = tree[i];
                }
                else{
                    tree[i/2] = 0;
                }
                break;
            }

            cmp = box_comp(tree[i-1], tree[i]); // -1, 0, 1

            if(cmp == -1){
                tree[i/2] = tree[i];
            }
            else if(cmp == 1){
                tree[i/2] = tree[i-1];
            }

        } // end for

        last -= tmp;
        tmp /= 2;
    }

    i = 1;
    max_index = tree[1];
    a=0;

    for(int j=0; j<log2(N); j++){
        if(tree[i*2] == max_index){
            arr[a++] = tree[i*2+1];
            i = i*2;
        }
        else{
            arr[a++] = tree[i*2];
            i = i*2+1;
        }
    }

    result = arr[0];
    for(int j=1; j<log2(N); j++){
        if(arr[j]==0) continue;

        if(box_comp(result, arr[j]) == -1){
            result = arr[j];
        }
    }

    box_report(result);
}
