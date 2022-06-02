#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Task{
    int money;
    int due;
};

struct comp{
    bool operator()(Task t1, Task t2){
        if (t1.money != t2.money) return t1.money < t2.money;
        return t1.due < t2.due;
    }
};

priority_queue<Task, vector<Task>, comp> tasksPQ;
vector<vector<int>> myTask;
vector<Task> inTask;
vector<Task> notInTask;

void inputData(int n, int t);
int findMax(int n, int t, int k);
bool pushTask(Task task, int t, int k);
bool full(vector<int> v, int k);
int myDate(int d);
int secondMax(int firstM, int k);

int main(){
    int n, t, k;
    int firstM, secondM;

    cin >> n >> t >> k;
    inputData(n, t);
    firstM = findMax(n, t, k);
    secondM = secondMax(firstM, k);
    cout << firstM << " " << secondM << endl;
}

void inputData(int n, int t){
    Task task;
    while (n-- > 0){
        cin >> task.money >> task.due;
        tasksPQ.push(task);
    }
    vector<int> v;
    while (t-- > 0){
        myTask.push_back(v);
    }
}

int findMax(int n, int t, int k){
    Task task;
    int sum = 0;
    while(true){
        if (tasksPQ.empty()) break;
        task = tasksPQ.top();
        tasksPQ.pop();

        if (!pushTask(task, t, k)) notInTask.push_back(task);
        else {
            sum += task.money;
        }
    }

    return sum;
}

bool pushTask(Task task, int t, int k){
    for (int date = min(task.due, t); date >= 1; date--){
        if (full(myTask[myDate(date)], k)) continue;
        else{
            myTask[myDate(date)].push_back(task.money);
            task.due = date;
            inTask.push_back(task);
            return true;
        }
    }
    return false;
}

bool full(vector<int> v, int k){
    if (v.size() == k) return true;
    return false;
}

int myDate(int d) {return d -1;}

int secondMax(int firstM, int k){
    sort(inTask.begin(), inTask.end(), [](Task t1, Task t2){
        if (t1.money != t2.money) return t1.money < t2.money;
        return t1.due < t2.due;
    });
    sort(notInTask.begin(), notInTask.end(), [](Task t1, Task t2){
        if (t1.money != t2.money) return t1.money > t2.money;
        return t1.due > t2.due;
    });

    Task lastTask, t;
    int sum = 0;
    bool findFlag = false;
    vector<int> sums;

    for (auto lastTask : inTask){
        for (auto t : notInTask){
            if (lastTask.due <= t.due){
                sum = firstM - (lastTask.money - t.money);
                if (sum == firstM) continue;
                sums.push_back(sum);
                break;
            }
        }
        if (findFlag) break;
    }

    //바꾸는것보다 하나 빼는게 이득이 큰 경우
    int n = 0;
    if (sums.size() != 0) n = *max_element(sums.begin(), sums.end());
    sum = max(n, firstM - inTask.front().money);
    return sum;
}