#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define NUM_TC 5

void swap(int& a, int& b) {
    if (a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
}
void flip(int lp, int rp, vector<int>& vec) {
    swap(lp, rp);
    reverse(vec.begin() + lp, vec.begin() + rp + 1);
    for (int i = lp; i <= rp; i++) {
        vec[i] *= -1;
    }
}
bool isInit(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != i + 1)    return false;
    }
    return true;
}
bool isOneFlip(vector<int> vec) {
    bool isLeftSearch = true, isRightSearch = false;
    int lp = -1, rp = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (isLeftSearch && vec[i] != i + 1) {
            lp = i;
            isLeftSearch = false;
            isRightSearch = true;
        }
        else if (isRightSearch && vec[i] == i + 1) {
            rp = i - 1;
            break;
        }
    }
    if (rp == -1)   rp = vec.size() - 1;
    flip(lp, rp, vec);
    if (isInit(vec))    return true;
    else                return false;
}
bool isTwoFlip(vector<int> vec) {
    int vecSize = vec.size();
    vector<int> vecIdx(vecSize + 1, -1);
    for (int i = 0; i < vecSize; i++) {
        vecIdx[abs(vec[i])] = i;
    }
    
    int lp = 0, rp = vecSize - 1;
    while (lp <= rp) {
        while (lp < rp && vec[lp] == lp + 1) {
            lp++;
        }
        if (vec[lp] > 0) {
            int idxSwap = vecIdx[lp + 1];
            flip(lp, idxSwap, vec);
            return isOneFlip(vec);
        } else {
            int idxSwap = vecIdx[lp + 1];
            if (-vec[lp] == idxSwap + 1 && -vec[idxSwap] == lp + 1) {
                flip(lp, idxSwap, vec);
                return isOneFlip(vec);
            }
        }
        while (lp < rp && vec[rp] == rp + 1) {
            rp--;
        }
        if (vec[rp] > 0) {
            int idxSwap = vecIdx[rp + 1];
            flip(rp, idxSwap, vec);
            return isOneFlip(vec);
        } else {
            int idxSwap = vecIdx[rp + 1];
            if (-vec[rp] == idxSwap + 1 && -vec[idxSwap] == rp + 1) {
                flip(rp, idxSwap, vec);
                return isOneFlip(vec);
            }
        }
        lp++;
        rp--;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    for (int tc = 0; tc < NUM_TC; tc++) {
        vector<int> vecNum(k, 0);
        for (int i = 0; i < k; i++)
            cin >> vecNum[i];

        if (isOneFlip(vecNum))      cout << "one\n";
        else if (isTwoFlip(vecNum)) cout << "two\n";
        else                        cout << "over\n";
    }
    return 0;
}