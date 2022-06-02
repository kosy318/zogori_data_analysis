#include <iostream>
#include <vector>
#include "timebomb.h"

using namespace std;

int len, result, answer;
vector<pair<int, int>> compPair;
vector<int> seconds;

int compareRecur(int start, int end, int depth) {
    if(start == end) return start;

    int left = start, right = end;
    if(end - start > 1) {
        int mid = (end - start) / 2;
        left = compareRecur(start, start + mid, depth+1);
        right = compareRecur(start + mid + 1, end, depth+1);
    }

    result = box_comp(left, right);
    compPair.push_back(make_pair(left, right));

    if(result == 1) return left;
    else return right;
}

int main()
{
    box_ready();
    len = box_size();

    int start = 1;
    int end = len;
    answer = compareRecur(start, end, 0);

    for(int i = 0; i < compPair.size(); ++i) {
        pair<int, int> now = compPair[i];
        if(now.first == answer) seconds.push_back(now.second);
        else if(now.second == answer) seconds.push_back(now.first);
    }

    answer = seconds[0];
    for(int i = 1; i < seconds.size(); ++i) {
        if(box_comp(answer, seconds[i]) == -1) answer = seconds[i];
    }
    box_report(answer);
    return 0;
}
