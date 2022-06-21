#include <iostream>
#include <vector>
using namespace std;

struct clean{
    clean(int f, int l, int c):
        firstDay{f}, lastDay{l}, cost{c}{};

    int firstDay;
    int lastDay;
    int cost;
};

vector<clean> db;
int N;
int maxLastDay = 0;
int maxCost = 0, cleanDay=0;

vector<clean> finder(int f){
    vector<clean> vec;
    int i=0;
    for(; i<N; i++){
        if(db[i].firstDay == f){
            vec.push_back(db[i]);
        }
    }
    return vec;
}

void dp(int day, int cost, int days){
    if(day > maxLastDay){
        if(cost > maxCost){
            maxCost = cost;
            cleanDay = days;
        } else if(cost == maxCost && cleanDay > days){
            cleanDay = days;
        }
        return;
    }
    vector<clean> vec = finder(day);
    while(!vec.empty()){
        clean tmp = vec.back();
        dp(tmp.lastDay+1, cost + tmp.cost - 10, days+tmp.lastDay-tmp.firstDay+1);
        vec.pop_back();
    }
    dp(day+1, cost, days);
}

int main(){
    cin >> N;
    int i, f, l, c;
    for(i=0; i<N; i++){
        cin >> f >> l >> c;
        db.push_back(clean(f, l, c));
        maxLastDay = max(maxLastDay, l);
    }

    dp(1, 0, 0);
    cout << 10 + maxCost << " " << cleanDay;
}
