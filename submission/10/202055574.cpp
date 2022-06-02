#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct job{
    job(int c, int d):
        cost{c}, date{d}{};
    int cost;
    int date;
};
vector<job> db;
int N, T, K;
int first, second;

void init(){
    cin >> N >> T >> K;
    int costTmp, dayTmp, i;
    while(N--){
        cin >>  costTmp >> dayTmp;
        db.push_back(job(costTmp, dayTmp));
    }

    sort(db.begin(), db.end(),
         [](job a, job b) -> bool{
            if(a.cost == b.cost)
                return a.date > b.date;
            return a.cost > b.cost;
         });
}

void findMaximamProfit(){
    int sum = 0, i;
    vector<vector<int>> sched;
    vector<int> check;
    vector<int> tmp;
    for(i=0; i<T; i++){
        sched.push_back(tmp);
    }
    for(auto tmp: db){
        if(check.size() >= T) break;
        int day = tmp.date - 1;
        while(day >= 0){
            if(sched[day].size() < K){
                sched[day].push_back(tmp.cost);
                sum += tmp.cost;
                if(sched[day].size() >= K &&
                   find(check.begin(), check.end(), day) == check.end()){
                    check.push_back(day);
                }
                break;
            }
            day--;
        }
    }
    first = sum;
    return;
}

void findSecondProfit(){
    int sum = 0;
    int sumTmp = 0;
    int i, j;
    vector<vector<int>> sched;
    vector<int> check;
    vector<int> tmp;

    for(i=0; i<T; i++){
        sched.push_back(tmp);
    }

    for(i=0; i<db.size(); i++){
        for(j=0; j<db.size(); j++){
            if(i==j) continue;
            if(j>i && db[j].cost == db[i].cost) continue;
            job tmp = db[j];
            if(check.size() >= T) break;
            int day = tmp.date - 1;
            while(day >= 0){
                if(sched[day].size() < K){
                    sched[day].push_back(tmp.cost);
                    sumTmp += tmp.cost;
                    if(sched[day].size() >= K &&
                       find(check.begin(), check.end(), day) == check.end()){
                        check.push_back(day);
                    }
                    break;
                }
                day--;
            }

        }
        if(sumTmp != first && sumTmp > sum) sum = sumTmp;
        check.clear();
        sched.clear();
        for(j=0; j<T; j++){
            sched.push_back(tmp);
        }
        sumTmp = 0;
    }
    second = sum;
    return;
}

int main(){
    init();
    findMaximamProfit();
    findSecondProfit();
    cout << first << " " << second;
}
