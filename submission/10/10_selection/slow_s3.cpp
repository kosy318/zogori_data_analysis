#include "bits/stdc++.h"
using namespace std;

int N,T,K, maximal =0 , second_maximal=0, min_c=100;
vector<pair<int,int>> task;

void Input(){
    cin >> N >> T >> K ;
    int c,d;
    for(int i =0; i<N; i++){
        cin >> c >> d ;
        task.push_back(make_pair(c,d));
    }
    sort(task.begin(),task.end(),greater<>());
}

bool select(int i, int day,vector<vector<int>> &schedule){
    for(int j = day-1; j > -1; j--){
        for(int k = 0; k<K; k++){
            if(schedule[k][j] == 0 ){
                schedule[k][j] = task[i].first;
                maximal += task[i].first;
                if(min_c >= task[i].first) min_c = task[i].first;
                return true;
            }
        }
    }
    return false;
}
void Slow(vector<vector<int>> &schedule){
    vector<pair<int,int>> temp;
    int day,x;
    for(int i = 0; i<N; i++){
        day = task[i].second;
        if( !select(i,day,schedule))    temp.push_back(task[i]);
    }


    for(int i=0; i<temp.size(); i++){
        day = temp[i].second;
        for(int j = day-1; j > -1; j--){
            for(int k = 0; k<K; k++){
                x =schedule[k][j]-temp[i].first;
                if(x!=0 && x < min_c) min_c = x;
            }
        }
    }
    second_maximal = maximal-min_c;
    return;
}
int main(){
    Input();
    vector<vector<int>> schedule(K,vector<int>(T,0));
    Slow(schedule);
    cout<<maximal<<" "<<second_maximal<<endl;

    return 0;
}