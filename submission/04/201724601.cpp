#include "timebomb.h"
#include <iostream>
#include <vector>

using namespace std;

int result;
vector<pair<int,int>> index;

int findMax(int lf, int ri);

int main(){
    int N, result, secondN;
    box_ready();
    N = box_size();
    int left = 1;
    int right = N;
    int max = findMax(left, right);
    secondN = index.back().second;
    for(int i = 0; i < index.size()-1; i++){
        if(index[i].first == max){
            result = box_comp(index[i].second, secondN);
            if(result == 1)
                secondN = index[i].second;
        }
    }
    box_report(secondN);
}

int findMax(int lf, int ri){
    if(lf+1 == ri){
        result = box_comp(lf,ri);
        if(result == 1){
            index.push_back(pair<int,int>(lf, ri));
            return lf;
        }else if(result == -1){
            index.push_back(pair<int,int>(ri, lf));
            return ri;
        }
    }
    if(lf == ri){
        return lf;
    }
    int mid = (lf+ri)/2;
    int x = findMax(lf, mid);
    int y = findMax(mid+1, ri);
    result = box_comp(x,y);
    if(result == 1){
        index.push_back(pair<int,int>(x, y));
        return x;
    }else if(result == -1){
        index.push_back(pair<int,int>(y, x));
        return y;
    }
}