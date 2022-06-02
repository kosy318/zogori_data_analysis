#include <bits/stdc++.h>
using namespace std;

bool compareReward(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}
bool compareDay(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main() {
    int N, T, k;
    cin >> N >> T >> k;
    vector<pair<int, int>> works(N); // c, d
    int valid[N]; //0 if works[i] is included in best
    for(int i=0; i<N; i++){
        cin >> works[i].first >> works[i].second;
        valid[i] = 1; //init valid
    }
    vector<pair<int, int>> best(T*k, make_pair(-1,-1));
    int index_best[T+1];
    int max_day_best[T+1];
    for(int i=0; i<T+1; i++){ //init max_day_best and index_best
        max_day_best[i] = i;
        index_best[i] = 0;
    }
    //sort works
    sort(works.begin(), works.end(), compareReward);

    //find the best solution(filling best, valid, max_day_best)(index_best is used for finding the best solution)
    int sum_first = 0;
    int element_min = numeric_limits<int>::max();
    int count = 0;
    for(int i=0; i<N; i++){
        if(count == T*k){break;}
        for(int j=works[i].second; j>0; j--){
            if(index_best[j] < k){
                best[(j-1)*k + index_best[j]].first = works[i].first;
                best[(j-1)*k + index_best[j]].second = works[i].second;
                valid[i] = 0;
                index_best[j] = index_best[j] + 1;
                sum_first += works[i].first;
                count ++;
                if(max_day_best[j] < works[i].second){max_day_best[j] = works[i].second;}
                if(element_min > works[i].first){element_min = works[i].first;}
                break;
            }
        }
    }

    //sort best(save at best_sorted to remove empty cell)
    vector<pair<int,int>> best_sorted;
    for(auto p : best){
        if(p.first != -1){best_sorted.push_back(p);}
    }
    sort(best_sorted.begin(), best_sorted.end(), compareDay);

    //complete max_day_best
    for(int i=T-1; i>0; i--){
        max_day_best[i] = max_day_best[max_day_best[i]];
    }

    //find minimum gap
    int len = best_sorted.size();
    int gap_min = numeric_limits<int>::max();
    for(int i=0; i<N; i++){
        if(valid[i] == 0){continue;}
        for(int j=0; j<len; j++){
            if(best[j].second > max_day_best[works[i].second]){break;}
            if(gap_min > best[j].first - works[i].first && best[j].first - works[i].first > 0){
                gap_min = best[j].first - works[i].first;
            }
        }
    }
    if(gap_min > element_min){gap_min = element_min;}//when removing is better than replacement

    cout << sum_first << " " << sum_first - gap_min;
}
