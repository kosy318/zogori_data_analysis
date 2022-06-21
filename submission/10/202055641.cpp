#include <iostream>
#include <cstring>
using namespace std;
int n,t,k,fir_max,sec_max,cnt;
int tmp1, tmp2;
int req[2][101]={0,};
int req2[2][101]={0,};
int task[51]={0,};
int s_max[11]={0,};

int main(){
    fir_max = 0;
    sec_max = 0;
    cnt = 0;
    cin >> n >> t >> k;
    for(int i=0;i<n;i++){
        cin >> req[0][i] >> req[1][i];
    }
    memcpy(req2,req,sizeof(req));
    for(int i=t;0<i;i--){
        for(int j=0;j<k;j++){
            tmp1 = 0;
            tmp2 = 0;
            for(int x=0;x<n;x++){
                if(tmp1<req[0][x]&&i<=req[1][x]){
                    tmp1=req[0][x];
                    tmp2=req[1][x];
                }
            }
            fir_max += tmp1;
            for(int x=0;x<n;x++){
                if(tmp1==req[0][x]&&tmp2==req[1][x]){
                    task[cnt]=x;
                    req[0][x]=0;
                    req[1][x]=0;
                    cnt++;
                    break;
                }
            }
        }
    }
    for(int i=0;i<t;i++){
        tmp1 = 102 ;
        for(int j=t*k-1;j>=(t-i-1)*k;j--){
            if(tmp1>req2[0][task[j]]){
                tmp1=req2[0][task[j]];
            }
        }
        tmp2=0;
        for(int x=0;x<n;x++){
            if(tmp2<req[0][x]&&(i+1)<=req[1][x]&&tmp1!=req[0][x]){
                tmp2=req[0][x];
            }
        }
        s_max[i] = fir_max - tmp1 + tmp2 ;
    }
    sec_max = 0;
    for(int i=0;i<t;i++){
        if(sec_max<s_max[i]){
            sec_max=s_max[i];
        }
    }

    cout << fir_max<<" "<<sec_max ;
}