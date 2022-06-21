#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vec;
string origin, after;
stack<int> s;
bool is_pos;


void btrk(int layer, int beforeIndex) {
    
    if (s.size() >= after.size()) {
        if ( (origin.size() - beforeIndex) % 2 ) {
            is_pos = true;
        }
    
        return;
    }
        
    for (int i : vec.at(layer)) {
        if (layer > 0 && i <= s.top()) {
            // do nothing
        }
        else if ( layer > 0 && i - s.top() != 1 && (i - s.top()) % 2 == 0 ) { 
            // do nothing
        }
        else {
            s.push(i);
            btrk(layer + 1, i);
            s.pop();
        }

        if (is_pos) 
            return; // 이미 가능하다는것을 알면 더이상 탐색할필요가 없음.
    }

    return;
}


int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> origin >> after;

        vec.clear();
        vec.resize(after.length(), vector<int>());

        for (int i = 0; i < after.length(); ++i) {
            for (int j = 0; j < origin.length(); ++j) {
                if ( after.at(i) == origin.at(j) ) {
                    vec.at(i).push_back(j);
                }
            }
        }

        while ( !s.empty() ) { // clearing stack s
            s.pop();
        }
        is_pos = false;

        btrk(0, 0);

        if (is_pos) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}