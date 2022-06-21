#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task{
    int start;
    int end;
    int money;
    bool operator > (Task t) {
        if (this->money != t.money)
            return this->money > t.money;
        return (this->end - this->start) < (t.end - t.start);
    }
};

struct TaskSum{
    int duration;
    int money;
    int house;
    bool operator > (TaskSum t) {
        if ((this->money - this->house * 10) != (t.money - t.house * 10))
            return (this->money - this->house * 10) > (t.money - t.house * 10);
        if (this->duration != t.duration)
            return this->duration < t.duration;
        return this->house < t.house;
    }
};

vector<Task> tasks;
vector<TaskSum> table;

void inputTasks();
void sortTasks();
void updateTable();
int findCutIndex(int i);

int main(){
    inputTasks();
    sortTasks();
    updateTable();

    int i = table.size()-1;
    cout << table[i].money - 10*table[i].house << " " << table[i].duration << endl;
}

void inputTasks(){
    int n;
    cin >> n;

    while(n-- > 0){
        Task t;
        TaskSum ts;
        cin >> t.start >> t.end >> t.money;
        tasks.push_back(t);
        table.push_back(ts);
    }
}

void sortTasks(){
    sort(tasks.begin(), tasks.end(), [](Task p1, Task p2){
        if (p1.end != p2.end) return p1.end < p2.end;
        if (p1.start != p2.start) return p1.start < p2.start;
    });
}

void updateTable(){
    for (int i = 0; i < tasks.size(); i++){
        if (i == 0){
            table[i].money = tasks[i].money;
            table[i].duration = tasks[i].end - tasks[i].start + 1;
            table[i].house = 0;
            continue;
        }
        else if (i == 1){
            if (tasks[i] > tasks[i - 1]){
                table[i].money = tasks[i].money;
                table[i].duration = tasks[i].end - tasks[i].start + 1;
                table[i].house = 0;
            }
            continue;
        }
        
        TaskSum t1, t2;
        int index = findCutIndex(i);
        t1.duration = tasks[i].end - tasks[i].start + 1;
        t1.money = tasks[i].money;
        t1.house = 0;
        if (index >= 0){
            t1.duration += table[index].duration;
            t1.money += table[index].money;
            t1.house += table[index].house + 1;
        }
        t2 = table[i-1];
        table[i] = (t1 > t2)? t1 : t2;
    }
}

int findCutIndex(int i){
    auto index = find_if(tasks.begin(), tasks.begin() + i, [&](Task t1){
        return t1.end >= tasks[i].start;
    });
    if (index == tasks.end()) return i-1;
    return index - tasks.begin() - 1;
}
