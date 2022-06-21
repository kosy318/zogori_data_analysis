#include <iostream>

using namespace std;
int startDate[100]={0};
int endDate[100]={0};
int profit[100]={0};
int dp[1100][2]={0,};

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>> startDate[i] >> endDate[i] >> profit[i] ;
    }
    int _d=1;
    for(int i=0;i<n;i++){
        if(_d < endDate[i]){
            _d = endDate[i];}
    }
    int curMax[2]={0,};
    for(int i=1;i<= _d ;i++){
        curMax[0]=dp[i-1][0];
        curMax[1]=dp[i-1][1];
        for(int j=0;j<n;j++){
            if(i<endDate[j]){
                continue;
            }
            else if(i== endDate[j] ){
                if(curMax[0]<dp[startDate[j]-1][0]+ profit[j] -10){
                    curMax[0]=dp[startDate[j]-1][0]+ profit[j] -10;
                    curMax[1]=dp[startDate[j]-1][1]- startDate[j] + endDate[j] +1;
                }
                if(curMax[0]< profit[j]){
                    curMax[0]= profit[j];
                    curMax[1]= endDate[j] - startDate[j]+1;
                }
            }
            dp[i][0]=curMax[0];
            dp[i][1]=curMax[1];
        }
    }
    cout<<dp[_d][0]<<" "<<dp[_d][1];
    
    return 0;
}