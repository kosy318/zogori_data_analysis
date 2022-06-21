#include <bits/stdc++.h>
#include "timebomb.h"
using namespace std;

int main() {
    box_ready();
    stack<vector<int>> resultStack;
    vector<int> result;
    int n = box_size();
    for (int i = 1; i < n; i += 2) {
        if (box_comp(i, i + 1) == 1) {
            result.push_back(i);
        } else {
            result.push_back(i + 1);
        }
    }
    if (n % 2 == 1) { result.push_back(n); }
    resultStack.push(result);
    n = result.size();
    result.clear();
    while (n > 1) {
        for (int i = 0; i < n - 1; i += 2) {
            if (box_comp(resultStack.top()[i], resultStack.top()[i + 1]) == 1) {
                result.push_back(resultStack.top()[i]);
            } else {
                result.push_back(resultStack.top()[i + 1]);
            }
        }
        if (n % 2 == 1) { result.push_back(resultStack.top()[n - 1]); }
        resultStack.push(result);
        n = result.size();
        result.clear();
    }
    int max_first = resultStack.top()[0];
    resultStack.pop();
    int max_second, pos;
    if (resultStack.top()[0] == max_first) {
        max_second = resultStack.top()[1];
        pos = 0;
    } else {
        max_second = resultStack.top()[0];
        pos = 1;
    }
    resultStack.pop();
    while (!resultStack.empty()) {
        if (pos * 2 + 1 < resultStack.top().size()) {
            if (resultStack.top()[pos * 2] == max_first) {
                if (box_comp(resultStack.top()[pos * 2 + 1], max_second) == 1) {
                    max_second = resultStack.top()[pos * 2 + 1];
                }
                pos = pos * 2;
            } else {
                if (box_comp(resultStack.top()[pos * 2], max_second) == 1) {
                    max_second = resultStack.top()[pos * 2];
                }
                pos = pos * 2 + 1;
            }
        }
        resultStack.pop();
    }
    if(!(box_size() == max_first && max_first%2 == 1)){
        if (box_comp(max_first - 1 + 2 * (max_first % 2), max_second) == 1) {
            max_second = max_first - 1 + 2 * (max_first % 2);
        }
    }
    box_report(max_second);
}