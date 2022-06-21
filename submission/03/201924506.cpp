#include <iostream>
#include <vector>

using namespace std;

int N;

int flip(vector<int> bread, int cnt) {
    if(cnt != 0) {
        int i = 0;
    
        for(; i < N; i++)
            if(bread[i] != i + 1)
                break;
        
        if(i == N)
            return cnt;
        else if(cnt == 2)
            return 99;
    }
    
    vector<pair<int, int>> flipRange;
    
    bool isStarted = true;
    bool isSequence = false;
    bool isNegative = false;
    
    int signCnt = 0;
    int startIndex = -1;
    
    for(int i = 0; i < N - 1; i++) {
        if(bread[i] != i + 1)
            isStarted = false;
        
        if(isStarted)
            continue;
        
        if(!isSequence) {
            startIndex = i;
        
            isNegative = bread[i] < 0;
            signCnt = 0;
            isSequence = true;
        }
        
        if(bread[i] < bread[i + 1] && bread[i] + 1 == bread[i + 1])
            continue;
        
        if(startIndex - i == 0) {
            if(i == 0 && bread[i + 1] > 0)
                flipRange.push_back({startIndex, i});
            else if(bread[i - 1] > 0 && bread[i + 1] > 0)
                flipRange.push_back({startIndex, i});
        }
        else
            flipRange.push_back({startIndex, i});
        
        if((bread[i] ^ bread[i + 1]) < 0) {
            signCnt += 1;
            
            if(signCnt == 2 && !isNegative)
                isSequence = false;
            else if(signCnt == 3 && isNegative)
                isSequence = false;
        } else {
            isSequence = false;
        }
    }
    
    if(isSequence)
        flipRange.push_back({startIndex, N - 1});
    
    if(bread[N - 2] > 0 && bread[N - 1] < 0)
        flipRange.push_back({N - 1, N - 1});
    
    int res = 99;
    
    for(int i = 0; i < flipRange.size(); i++) {
        if(res == 1)
            return res;
        
        vector<int> flipedBread(bread);
        
        int start = flipRange[i].first;
        int end = flipRange[i].second;
        
        if((end - start + 1) % 2 != 0)
            flipedBread[start + (end - start + 1) / 2] *= -1;
        
        for(int j = 0; j < (end - start + 1) / 2; j++) {
            int temp = flipedBread[j + start] * -1;
            flipedBread[j + start] = flipedBread[end - j] * -1;
            flipedBread[end - j] = temp;
        }
                
        res = min(res, flip(flipedBread, cnt + 1));
    }
    
    return res;
}

int main() {
    cin >> N;
    
    for(int q = 0; q < 5; q++) {
        vector<int> bread(N);
        
        for(int i = 0; i < N; i++) {
            cin >> bread[i];
        }
        
        int res = flip(bread, 0);
        
        if(res == 1)
            cout << "one" << endl;
        else if(res == 2)
            cout << "two" << endl;
        else
            cout << "over" << endl;
    }
    
    return 0;
}
