#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Task {
public:
    int index;
    int cash;
    int dueDate;
};

int main()
{
    int N, T, k;
    
    cin >> N >> T >> k;
    
    vector<Task> tasks(N); 
    vector<vector<Task>> selectedTasks;
    vector<int> selectedTaskIndexes;
    
    int maximalProfit = 0, secondMaximal = 0;
    
    for(int i = 0; i < N; i++) {
        cin >> tasks[i].cash >> tasks[i].dueDate;
        
        tasks[i].dueDate--;
        tasks[i].index = i;
    }
    
    for(int i = 0; i < T; i++) {
        selectedTasks.push_back(vector<Task>());
    }
    
    sort(tasks.begin(), tasks.end(), [](const Task & a, const Task & b) -> bool
        { 
            return a.cash > b.cash; 
        });
    
    for(int i = 0; i < N; i++) {
        int dueDate = tasks[i].dueDate;
    
        for(int j = 0; j <= dueDate; j++) {
            if(selectedTasks[dueDate - j].size() < k) {
               selectedTasks[dueDate - j].push_back(tasks[i]); 
               
               selectedTaskIndexes.push_back(tasks[i].index);
               
               maximalProfit += tasks[i].cash;
               
               break;
            }
        }
    }

    for(int i = 0; i < T; i++) {
        int tempMaximalProfit = maximalProfit;
        
        for(int j = 0; j < selectedTasks[i].size(); j++) {
            tempMaximalProfit -= selectedTasks[i][j].cash;
            
            if(tempMaximalProfit > secondMaximal)
                secondMaximal = tempMaximalProfit;
            
            for(int k = 0; k < N; k++) {
                auto it = find(selectedTaskIndexes.begin(), selectedTaskIndexes.end(), tasks[k].index);
                
                if(it == selectedTaskIndexes.end()) {
                    if(tasks[k].dueDate >= i && tempMaximalProfit + tasks[k].cash > secondMaximal && tempMaximalProfit + tasks[k].cash < maximalProfit) {
                        secondMaximal = tempMaximalProfit + tasks[k].cash;
                    }
                }
            }
            
            tempMaximalProfit += selectedTasks[i][j].cash;
        }
    }
    
    cout << maximalProfit << " " << secondMaximal;
    
    return 0;
}
