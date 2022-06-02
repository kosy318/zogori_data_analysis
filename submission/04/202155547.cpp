#include <iostream>
#include "timebomb.h"

using namespace std;
int index1 = 1;
int index2[5000];
int largest;
int Compare[5000];
int new_arr[5000][5000];

void store_arr(int N){
    for (int i=1; i<=N/2; i++){
        if (box_comp(new_arr[index1][2*i-1],new_arr[index1][2*i]) < 0){
            new_arr[index1+1][i] = new_arr[index1][2*i];
        }
        else{
            new_arr[index1+1][i] = new_arr[index1][2*i-1];
        }
    }
    if (N % 2) new_arr[index1+1][N/2 +1] = new_arr[index1][N];
}
void find_compared(int N){
    for (int i=1; i<index1; i++){
        for (int j=1; j<=index2[i]; j++){
            if(new_arr[i][j] == largest){
                if (j % 2) Compare[i] = new_arr[i][j+1];
                else Compare[i] = new_arr[i][j-1];
            }
        }
    }
}
int find_index(int N){

    for (int i=1; i<=N; i++){
        new_arr[index1][i] = i;
    }
    while(N >= 2){
        store_arr(N);
        index2[index1] = N;
        index1 ++;
        if (N % 2) N = N/2 +1;
        else N = N/2;
    }
    largest = new_arr[index1][1];
    return 0;
}
int find_second_largest(int N){
    int i,ans;
    for (i=1; i<N; i++){
        if (Compare[i] != 0) {
            ans = Compare[i];
            break;
        }
    }

    for (int j=i+1; j<N; j++){
        if (Compare[j] != 0)
            if (box_comp(ans, Compare[j]) < 0)
                ans = Compare[j];
    }
    return ans;
}

int main()
{
    int N, temp, answer;
    box_ready();
    N = box_size();

    temp = find_index(N);
    find_compared(N);
    answer = find_second_largest(index1);

    box_report(answer);
    return 0;
}
