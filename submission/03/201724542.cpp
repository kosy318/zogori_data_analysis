#include <bits/stdc++.h>
using namespace std;
int N;

struct compare {
    bool operator() (pair<int,int> &a, pair<int,int> &b) {
        if (abs(a.first) == abs(b.first)) return abs(a.second) < abs(b.second);
        return abs(a.first) < abs(b.first);
    }
};

void flipFrame(vector<int> &frame, vector<int> &diff, int left, int right) {
    while(left <= right) {
        int temp = frame[left];
        frame[left] = frame[right] * -1;
        frame[right] = temp * -1;
        diff[left] = abs(frame[left]) - (left + 1);
        diff[right] = abs(frame[right]) - (right + 1);
        left++; right--;
    }
}

bool checkAlreadySortedWithSign(vector<int> &frame) {
    int prev = frame.front();
    for (int &n: frame) {
        if (n < prev || n < 0) return false;
        prev = n;
    }
    return true;
}

int checkAlreadySortedWithoutSign(vector<int> &frame) {
    int prev = abs(frame.front());
    int cntMinus = 0;
    for (int &n: frame) {
        if (abs(n) < prev) return 3;
        if (n < 0) cntMinus++;
        prev = abs(n);
    }
    return cntMinus;
}

int flip(vector<int> frame, vector<int> diff, int cnt) {
    if (cnt > 2) return cnt; 

    if (checkAlreadySortedWithSign(frame)) {
        if (cnt == 0) return 2;
        else return cnt;
    }
    
    int result = checkAlreadySortedWithoutSign(frame);
    if (result < 3) return cnt + result;

    if (cnt >= 2) return 3;

    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
    for (int i = 0; i < N; i++) {
        if (diff[i] != 0) pq.push({diff[i], i});
    }
    int C = 30;
    while(!pq.empty() && C) {
        C--;
        pair<int,int> item = pq.top(); pq.pop();
        int offset = item.first;
        int index = item.second;

        int left = min(index, index + offset);
        int right = max(index, index + offset);
        
        flipFrame(frame, diff, left, right);
        int temp = flip(frame, diff, cnt + 1);
        if (temp < 3) return temp;
        result = min(result ,temp);
        flipFrame(frame, diff, left, right);
    }
    return result;
}

void ans(vector<int> frame) {
    vector<int> diff(N);
    for (int i = 0; i < N; i++) {
        diff[i] = abs(frame[i]) - (i + 1);
    }
    
    int k = flip(frame, diff, 0);
    switch(k) {
        case 1:
            cout << "one\n";
            break;
        case 2:
            cout << "two\n";
            break;
        default:
            cout << "over\n";
    }
}

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    vector<vector<int>> frames(5, vector<int>(N));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++) {
            cin >> frames[i][j];
        }
        ans(frames[i]);
    }
    return 0;
}
