#include<iostream>
#include<string>
#include<vector>
using namespace std;

int findIndex(string str,char x, int goalSize){
    for(int i=0;str.length()-i>=goalSize;i++){
        if(str[i]==x&&(str.length()-i-goalSize)%2==0) return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    string origin,goal;
    for(int i=0;i<N;i++){
        cin>>origin;
        cin>>goal;
        int startI=findIndex(origin,goal[0],goal.length());
        if(startI==-1) cout<<"NO"<<endl;
        else{
            int x=startI,y=0;    //x는 origin의 index, y는 goal의 index;
            int flag=0;
            while(x<=origin.length()&&origin.length()-x>=goal.length()-y){
                if(y==goal.length()){
                    if((origin.length()-x)%2==0) flag=1;
                    break;
                }
                //cout<<'('<<x<<':'<<origin[x]<<'|'<<y<<':'<<goal[y]<<')'<<endl;
                if(origin[x]!=goal[y]){
                    x+=2;   //2칸 점프
                }else{
                    x++;
                    y++;
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            }
    }

    return 0;
}