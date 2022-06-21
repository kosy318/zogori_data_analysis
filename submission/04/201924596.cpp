#pragma once
#include <bits/stdc++.h>
#include "timebomb.h"
using namespace std;

vector< pair<int, int> >  matchRecord;

int findFirstMax(vector<int>& winner, bool record) {
    
    while (winner.size() > 1) {
        vector<int> newWinner;
        newWinner.reserve(winner.size() / 2 + 1);

        for (int i = 0; i < winner.size() / 2; ++i) {
            int j = winner.size() - 1 - i;
            
            if ( box_comp(winner[i], winner[j]) == 1 ) { // B[i] > B[j]
                newWinner.push_back(winner[i]);
            }
            else {
                newWinner.push_back(winner[j]);
            }

            if (record)
                matchRecord.push_back( make_pair(winner[i], winner[j]) );
        }

        if (winner.size() % 2) 
            newWinner.push_back( winner[winner.size() / 2] );

        winner = newWinner;
    }

    return winner[0];
}

int main() {
    int N, result;
    vector<int> winner;
    // init
    box_ready();
    N = box_size();
    // vector size reserve
    winner.reserve(N);
    matchRecord.reserve(2*N + 2);
    // fill initial winner's record 
    for (int i = 1; i <= N; ++i)
        winner.push_back(i);
    // find first max
    int firstMax = findFirstMax(winner, true);
    
    // find who fight with first max
    vector<int> secondWinner;
    secondWinner.reserve(N);
    for (auto p : matchRecord) {
        if (p.first == firstMax) {
            secondWinner.push_back(p.second);
        }
        else if (p.second == firstMax) {
            secondWinner.push_back(p.first);
        }
    }
    // find second max (find first max in group of candidate of second max)
    int secondMax = findFirstMax(secondWinner, false);

    box_report(secondMax);

    return 0;
}