#include "timebomb.h"


int max(int,int[]);

int N;
int idx=0;
int c=0;
int r[10000][2];
int heavy[10000]={0,};
int main(){
    int bomb;
    box_ready();
    N=box_size();
    for(int i=0;i<N;i++){
        heavy[i]=i+1;
    }
    int t=max(N,heavy);
    for(int i=0;i<N;i++){
        heavy[i]=0;
    }
    idx=0;
    for(int i=0;i<N;i++){
        if(r[i][0]==t){
            heavy[idx]=r[i][1];
            idx++;
        }
        else if(r[i][1]==t){
            heavy[idx]=r[i][0];
            idx++;
        }
    }
    bomb=max(idx,heavy);
    box_report(bomb);

    return 0;
}

int max(int l,int arr[]){
    if(l==1){
        return arr[0];
    }
    idx=0;
    int i=0;
    int result;
    while(i<l){
        if(i==l-1){
            arr[idx]=arr[i];
            break;
        }
        result=box_comp(arr[i],arr[i+1]);
        r[c][0]=arr[i];
        r[c][1]=arr[i+1];
        c++;
        if(result==1){
            arr[idx]=arr[i];
            idx++;
        }
        else if(result==-1){
            arr[idx]=arr[i+1];
            idx++;
        }
        else if(result==0){
            arr[idx]=arr[i];
            break;
        }
        i+=2;
    }
    return max((l+1)/2,arr);
}