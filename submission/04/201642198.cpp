#include "timebomb.h"
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 5000
#define pb push_back

vector<vector<int>> lighterBox (MAX_N + 1);
set<int> setHeavyBox, setLightBox;

void classifyTwoBox(int result, int x, int y) {
    int heavy = 0, light = 0;
    if (result == 1) {
        heavy = x; light = y;
    } else {
        heavy = y; light = x;
    }
    setHeavyBox.insert(heavy);
    setLightBox.insert(light);
    lighterBox[heavy].pb(light);

    setHeavyBox.erase(light);
    for (int lighterOne : lighterBox[light])
        setLightBox.erase(lighterOne);
}
void discardLighterBox(int result, int x, int y) {
    int heavy = 0, light = 0;
    if (result == 1) {
        heavy = x; light = y;
    } else {
        heavy = y; light = x;
    }
    setLightBox.erase(light);
}

int main() {
    int N, result, answer;
    int heavy, light;
    box_ready();
    N = box_size();
    int i = 1, j = N;
    while (i < j) {
        result = box_comp(i, j);
        classifyTwoBox(result, i, j);
        i++; j--;
    }
    if (i == j) {
        set<int>::iterator it = setHeavyBox.cbegin();
        j = *it;
        result = box_comp(i, j);
        classifyTwoBox(result, i, j);
    }
    set<int>::iterator lp, rp;
    while (setHeavyBox.size() > 1) {
        set<int> setHeavyTmp(setHeavyBox);
        lp = setHeavyTmp.cbegin();
        rp = prev(setHeavyTmp.cend());
        int t = 0;
        int halfSize = setHeavyTmp.size() / 2;
        while (t < halfSize) {
            i = *lp; j = *rp;
            result = box_comp(i, j);
            classifyTwoBox(result, i, j);
            lp++; rp--; t++;
        }
    }
    while (setLightBox.size() > 1) {
        set<int> setLightTmp(setLightBox);
        lp = setLightTmp.cbegin();
        rp = prev(setLightTmp.cend());
        int t = 0;
        int halfSize = setLightTmp.size() / 2;
        while (t < halfSize) {
            i = *lp; j = *rp;
            result = box_comp(i, j);
            discardLighterBox(result, i, j);
            lp++; rp--; t++;
        }
    }
    set<int>::iterator iter = setLightBox.cbegin();
    answer = *iter;
    box_report(answer);
    return 0;
}