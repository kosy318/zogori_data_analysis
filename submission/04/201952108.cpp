#include "timebomb.h"
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

struct boxCompare{
    int big;
    int small;
};

int findBiggest(deque<boxCompare> boxes, vector<boxCompare>& biggerBoxes){
    int biggest, result;
    boxCompare box;
    while(!boxes.empty()){
        boxCompare b1 = boxes.front(); boxes.pop_front();
        boxCompare b2 = boxes.front(); boxes.pop_front();
        
        result = box_comp(b1.big, b2.big);
        if (result == 1){
            biggerBoxes.push_back(b1);
            box.big = b1.big;
            box.small = b2.big;
        }
        else if(result == -1){
            biggerBoxes.push_back(b2);
            box.big = b2.big;
            box.small = b1.big;
        }
        else continue;

        boxes.push_back(box);

        if (boxes.size() == 1){
            biggest = boxes.front().big;
            biggerBoxes.push_back(boxes.front());
            break;
        }
    }
    return biggest;
}

int main(){
    vector<boxCompare> biggerBoxes;
    int N, biggest = 0, secondBig = 0;

    box_ready();
    N = box_size();

    //묶어서 deque에 넣기
    deque<boxCompare> boxes;
    boxCompare box;
    int result;
    for (int i = 1; i < N + 1; i += 2){
        if (i == N){
            box.big = i;
            box.small = i;
            boxes.push_back(box);
            break;
        }
        result = box_comp(i, i+1);
        
        if (result == 1) {
            box.big = i;
            box.small = i + 1;
        }
        else if (result == -1){
            box.big = i + 1;
            box.small = i;
        }
        else continue;
        boxes.push_back(box);
    }
    
    //deque로 찾기
    biggest = findBiggest(boxes, biggerBoxes);

    deque<boxCompare> secondQ;
    vector<int> seconds;
    for (auto box : biggerBoxes){
        if (box.big == biggest && box.small != biggest) 
            seconds.push_back(box.small);
    }
    if (seconds.size() == 1){
        secondBig = seconds[0];
        box_report(secondBig);
    }
    
    int a, b;
    for (int i = 0; i < seconds.size(); i+=2){
        if (i == seconds.size() - 1){
            box.big = seconds[i];
            box.small = seconds[i];
            secondQ.push_back(box);
            break;
        }
        a = seconds[i]; b = seconds[i + 1];
        result = box_comp(a, b);
        
        if (result == 1) {
            box.big = a;
            box.small = b;
        }
        else if (result == -1){
            box.big = b;
            box.small = a;
        }
        else continue;
        secondQ.push_back(box);
    }

    secondBig = findBiggest(secondQ, biggerBoxes);
    box_report(secondBig);
}