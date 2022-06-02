#include <iostream>
#include "timebomb.h"
using namespace std;

struct box {
    int index, weight;
    operator int() const {
        return weight;
    }
};
template<typename T>
class completeBoxTree {
private:
    int lowLeaf;
    int offset;
    int* tree;
    int num;
    T* box;
public:
    completeBoxTree(T* theBox, int N) {
        tree = NULL;
        initialize(theBox, N);
    }
    ~completeBoxTree() {
        delete[] tree;
    }
    void play(int p, int leftChild, int rightChild) {
        tree[p] = (box[leftChild] >= box[rightChild]) ? leftChild : rightChild;
        while ((p % 2 == 1) && p > 1) {
            tree[p / 2] = (box[tree[p - 1]] >= box[tree[p]]) ? tree[p - 1] : tree[p];
            p /= 2;
        }
    }
    void initialize(T* theBox, int N) {
        int n = N;
        box = theBox;
        num = n;
        delete[] tree;
        tree = new int[n];
        int i, s;
        for (s = 1; 2 * s <= n - 1; s += s);
        lowLeaf = 2 * (n - s);
        offset = 2 * s - 1;
        for (i = 2; i <= lowLeaf; i += 2) {
            play((offset + i) / 2, i - 1, i);
        }
        if ((n % 2) == 1) {
            play(n / 2, tree[n - 1], lowLeaf + 1);
            i = lowLeaf + 3;
        }
        else {
            i = lowLeaf + 2;
        }
        for (; i <= n; i += 2) {
            play((i - lowLeaf + n - 1) / 2, i - 1, i);
        }
    }
    int heavy() const {
        return tree[1];
    }
    void secondBox(int theBox) {
        int n = num;
        int mN, lC, rC;
        if (theBox <= lowLeaf) {
            mN = (offset + theBox) / 2;
            lC = 2 * mN - offset;
            rC = lC + 1;
        }
        else {
            mN = (theBox - lowLeaf + n - 1) / 2;
            if (2 * mN == n - 1) {
                lC = tree[2 * mN];
                rC = theBox;
            }
            else {
                lC = 2 * mN - n + 1 + lowLeaf;
                rC = lC + 1;
            }
        }

        tree[mN] = (box[lC] >= box[rC]) ? lC : rC;

        if ((mN == n - 1) && (n % 2 == 1)) {
            mN /= 2;
            tree[mN] = (box[tree[n - 1]] <= box[lowLeaf + 1]) ? tree[n - 1] : lowLeaf + 1;
        }

        mN /= 2;
        for (; mN >= 1; mN /= 2) {
            tree[mN] = (box[tree[2 * mN]] >= box[tree[2 * mN + 1]]) ? tree[2 * mN] : tree[2 * mN + 1];
        }
    }
};
int main()
{
    int N, result, this;
    box_ready();
    N = box_size();
    box* theBox = new box[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> theBox[i].weight;
        theBox[i].index = i;
    }
    completeBoxTree<box>* w = new completeBoxTree<box>(theBox, N);
    int heavyindex = w->heavy();
    theBox[heavyindex].weight = 0;
    w->secondBox(heavyindex);
    this = w->heavy();
    box_report(this);
}
