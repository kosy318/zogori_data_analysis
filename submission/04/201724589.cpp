#include <iostream>
#include <vector>
#include <queue>
#include "timebomb.h"

using namespace std;

typedef struct {
    int num1;
    int num2;
    int outnum;
} Block;
vector<Block> VB;

int main() {
    int N, result, th;
    queue<int> q;
    box_ready();      
    N = box_size();   
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    int i, j;
    while (true) {
        if (q.empty()) break;
        i = q.front();
        q.pop();
        if (q.empty()) {
            j = i;
            result = i;
        }
        else {
            j = q.front();
            q.pop();
            result = box_comp(i, j);
            if (result == 1) {
                result = i;
            }
            else if (result == -1) {
                result = j;
            }
            else continue;
        }
        VB.push_back({ i,j,result });
        if (!q.empty())
            q.push(result);
    }
    int maxnum = VB.back().outnum;
    for (auto iter = VB.begin(); iter != VB.end(); iter++) {
        if ((*iter).outnum == maxnum) {
            if ((*iter).num1 == maxnum) q.push((*iter).num2);
            else q.push((*iter).num1);
        }
    }
    while (true) {
        if (q.empty()) break;
        i = q.front();
        q.pop();
        if (q.empty()) {
            j = i;
            result = i;
        }
        else {
            j = q.front();
            q.pop();
            result = box_comp(i, j);
            if (result == 1) {
                result = i;
            }
            else if (result == -1) {
                result = j;
            }
            else continue;
        }
        if (!q.empty())
            q.push(result);
    }
    th = result;
    box_report(th); 
    return 0;
}
