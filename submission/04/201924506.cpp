#include "timebomb.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    box_ready();
    
    int N;
    
    N = box_size();
    
    vector<vector<int>> compareLog;
    vector<int> indexes;
    
    compareLog.push_back(vector<int>());
    
    for(int i = 0; i < N; i++) {
        compareLog.push_back(vector<int>());
        indexes.push_back(i + 1);
    }

    int championIndex;
    int beanIndex;

    while(true) {
        vector<int> winner;
        
        for(int i = 0; i < indexes.size() - 1; i += 2) {
            if(box_comp(indexes[i], indexes[i + 1]) == 1) {
                compareLog[indexes[i]].push_back(indexes[i + 1]);
                
                winner.push_back(indexes[i]);
            }
            else {
                compareLog[indexes[i + 1]].push_back(indexes[i]);
                
                winner.push_back(indexes[i + 1]);
            }
        }
        
        if(indexes.size() % 2 != 0)
            winner.push_back(indexes[indexes.size() - 1]);
    
        if(winner.size() == 2) {
            if(box_comp(winner[0], winner[1]) == 1) {
                championIndex = winner[0];
                beanIndex = winner[1];
            }
            else {
                championIndex = winner[1];
                beanIndex = winner[0];
            }
            
            for(int i = 0; i < compareLog[championIndex].size(); i++) {
                if(box_comp(compareLog[championIndex][i], beanIndex) == 1) {
                    beanIndex = compareLog[championIndex][i];
                }
            }
    
            box_report(beanIndex);
            
            break;
        }
        
        indexes = winner;
    }
        
    return 0;
}
