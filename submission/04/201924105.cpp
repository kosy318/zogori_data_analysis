#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "timebomb.h"
using namespace std;

int main() {
    int n, result, first, second;
    queue<int> winners;
    // index number and number of box which is lighter than the index.
    map<int, vector<int>> record;
    box_ready();
    n = box_size();
    for(int i=1, j=n; i<=j; i++, j--) {
        if(i == j) {
            winners.push(i);
            break;
        }
        result = box_comp(i, j);
        if(result == -1) {
            winners.push(j);
            record[j].push_back(i);
        } else {
            winners.push(i);
            record[i].push_back(j);
        }
    }
    
    while(winners.size() > 1) {
        int i = winners.front();
        winners.pop();
        int j = winners.front();
        winners.pop();
        result = box_comp(i, j);
        if(result == -1) {
            winners.push(j);
            record[j].push_back(i);
        } else {
            winners.push(i);
            record[i].push_back(j);
        }    
    }
    first = winners.front();
    winners.pop();
    
    for(int i=0, j=record[first].size()-1; i<=j; i++, j--) {
        if(i == j) {
            winners.push(record[first][i]);
            break;
        }
        result = box_comp(record[first][i], record[first][j]);
        if(result == -1) {
            winners.push(record[first][j]);
        } else {
            winners.push(record[first][i]);
        }
    }
    while(winners.size() > 1) {
        int i = winners.front();
        winners.pop();
        int j = winners.front();
        winners.pop();
        result = box_comp(i, j);
        if(result == -1) {
            winners.push(j);
        } else {
            winners.push(i);
        }    
    }
    second = winners.front();
    box_report(second);
}