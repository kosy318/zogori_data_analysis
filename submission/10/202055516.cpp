#include<bits/stdc++.h>

using namespace std;

int N, T, k, c, d;
int maxCost=0, secondCost=0, minCost=100;
int schedule[6][11] = {0, };
priority_queue<pair<int, int>> work;
priority_queue<pair<int, int>> extra;


void input() {
    cin >> N >> T >> k;
    for(int i=0; i<N; i++){
        cin >> c >> d;
        work.push({c, d});

    }
}


void findMax() { // �ִ����� ���ϱ�
    bool found = 0;
    for(int i=0; i<N; i++) {
        c = work.top().first;
        d = work.top().second;
        work.pop();
        found = 0;
        for(int j=d; j>0; j--) {
            for(int m=1; m<=k; m++) {
                if(schedule[m][j]==0) {
                    schedule[m][j]=c;
                    maxCost += c;
                    if(c < minCost) minCost = c;
                    found = 1;
                    break;
                }
            }
            if(found) break;
        }
        if(!found) {
            // ���������� left�� �ֱ�
            extra.push({c, d});
        }
    }
}


void findSecond() {
    // ������ �͵� �߿��� �� �ϳ� �ٲٱ�
    while(!extra.empty()) {
        c = extra.top().first;
        d = extra.top().second;
        extra.pop();
        for(int m=d; m>0; m--) {
            if(schedule[k][m] != c) {
                int newCost = maxCost - schedule[k][m] + c;
                if(newCost > secondCost) secondCost = newCost;
            }
        }
    }

    // �� �ϳ� ���ϱ�
    c = maxCost - minCost;
    if(c > secondCost) secondCost = c;
}


void output() {
    cout << maxCost << " " << secondCost <<endl;
}


int main() {
    input();
    findMax();
    findSecond();
    output();
}
