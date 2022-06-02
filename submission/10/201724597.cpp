#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define FOR(i,j) for(int i=0; i<j; i++)

using namespace std;

int find_max();

int N, T, K;
int schedule[5][10] = {0};
pair<int, int> work;
vector<pair<int, int>> workList;
vector<int> dontWork;
vector<int> minWork;

int y = 0;

int main()
{
    cin>> N >> T >> K;

    int c, d;
    FOR(i,N){
        cin>> c >> d;
        work.first = c;
        work.second = d;
        workList.push_back(work);
    }

    sort(workList.rbegin(), workList.rend()); //가격에 따라 저장

    int max_val;
    max_val = find_max();

    cout<< max_val << " ";

    if(!dontWork.empty()){
    FOR(i,dontWork.size()){
         FOR(j,K){
            FOR(k,workList[dontWork[i]].second){
                minWork.push_back(schedule[j][k]-workList[dontWork[i]].first);
            }
        }
    }
    }
    if(!minWork.empty())    sort(minWork.begin(),minWork.end());
    else minWork.push_back(100);

    int v1 = max_val-minWork[0];
    int v2 = max_val-workList[y].first;
    if(v1>v2) cout<< v1 <<endl;
    else cout<< v2 <<endl;

    return 0;
}

int find_max(){
    int p, x;
    int sum = 0;
    FOR(i,N){
        x = 0;
        p = workList[i].second-1;
        for(int k=p; k>=0; k--){
            FOR(j,K){
                if(schedule[j][k]<workList[i].first){
                    schedule[j][k] = workList[i].first;
                    sum += workList[i].first;
                    x = 1;
                    y = i;
                    break;
                }
                else if(schedule[j][k]==workList[i].first){
                    x = 2;
                    y = i;
                }

            }
            if(x == 1) break;
        }
        if(x == 0) dontWork.push_back(i);
    }
    return sum;
}
