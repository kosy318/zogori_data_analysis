#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inputData();
void countFlip(const vector<int>& fishPan);
int startFront(const vector<int> fishPan);
int startBack(const vector<int> fishPan);
int originPos(int i);
void reversePan(vector<int>& pan, int startI, int endI);
bool isSame(const vector<int>& fishPan);

int main(){
    inputData();
}

void inputData(){
    vector<int> fishPan;
    int panSize, n = 5;
    cin >> panSize;

    while (n-- > 0){
        for (int i = 0; i < panSize; i++){
            int fish;
            cin >> fish;
            fishPan.push_back(fish);
        }
        countFlip(fishPan);

        fishPan.clear();
    }
}

void countFlip(const vector<int>& fishPan){
    int cnt;
    cnt = startFront(fishPan);
    if (cnt == 1 || cnt == 2) return;
    cnt = startBack(fishPan);
}

int startFront(const vector<int> fishPan){
    vector<int> copyPan = fishPan;
    int cnt = 0;
    bool end = false;

    for (int target = 1; target < copyPan.size() + 1; target++){
        if (end == true || cnt > 2) break;
        if (target == copyPan[originPos(target)]) continue;

        for (int i = target - 1; i < copyPan.size(); i++){
            if (target == abs(copyPan[i])){
                cnt++;
                reversePan(copyPan, originPos(target), i);

                if (isSame(copyPan)) end = true;
                break;
            }
        }
    }
    if (end){
        if      (cnt == 1)  cout << "one" << endl;
        else if (cnt == 2)  cout << "two" << endl;
    }
    return cnt;
}

int startBack(const vector<int> fishPan){
    vector<int> copyPan = fishPan;
    int cnt = 0;
    bool end = false;

    for (int target = copyPan.size() + 1; target >= 1 ; target--){
        if (end == true || cnt > 2) break;
        if (target == copyPan[originPos(target)]) continue;

        for (int i = originPos(target); i >= 0; i--){
            if (target == abs(copyPan[i])){
                cnt++;
                reversePan(copyPan, i, originPos(target));

                if (isSame(copyPan)) end = true;
                break;
            }
        }
    }
    
    if      (cnt == 1)  cout << "one"  << endl;
    else if (cnt == 2)  cout << "two"  << endl;
    else                cout << "over" << endl;
    return cnt;
}

int originPos(int i){ return i - 1; }

void reversePan(vector<int>& pan, int startI, int endI){
    if (startI == endI) pan[startI] *= -1;
    else{
        reverse(pan.begin() + startI, pan.begin() + (endI + 1));
        for (int i = startI; i < endI + 1; i++) pan[i] *= (-1);
    }
}

bool isSame(const vector<int>& fishPan){
    for (auto i = 0; i < fishPan.size(); i++)
        if (fishPan[i] != i + 1) return false;
    return true;
}
