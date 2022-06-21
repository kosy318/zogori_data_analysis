#include "timebomb.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getMaxIndex(vector<int> idxList)
{
    if (idxList.size() == 1)
        return idxList[0];
    int maxIndex = idxList[idxList.size() - 1];
    vector<int>::iterator vec_first;
    for (vec_first = idxList.begin(); vec_first != idxList.end() - 1; vec_first++)
    {
        if (maxIndex == *vec_first)
        {
            continue;
        }
        if (box_comp(maxIndex, *vec_first) == -1)
        {
            maxIndex = *vec_first;
        }
    }
    return maxIndex;
}

double log2(double x, double base)
{
    return log(x) / log(base);
}

int main()
{
    int N, result, that;
    box_ready();
    N = box_size();
    vector<int> idxList(N);
    vector<int> maxList;
    int logN = int(round(N/log2(N, 2)));

    for (int i = 0; i < N; i++)
    {
        idxList[i] = i+1;
    }

    for (int i = 0; i < int(log2(N, 2)); i++){
        if (i == int(log2(N, 2) - 1))
        {
            vector<int> idxs{&idxList[i * logN], &idxList[idxList.size()]};
            maxList.push_back(getMaxIndex(idxs));
            continue;
        }
        vector<int> idxs{&idxList[i * logN], &idxList[i * logN + logN]};
        maxList.push_back(getMaxIndex(idxs));
    }

    int realMax = getMaxIndex(maxList);

    vector<int> secondMaxList;
    for (int i = 0; i < maxList.size(); i++)
    {
        if (maxList[i] != realMax)
        {
            secondMaxList.push_back(maxList[i]);
        }
    }

    that = getMaxIndex(secondMaxList);
    idxList[realMax - 1] = that;
    for (int i = 0; i < int(log2(N, 2)); i++)
    {
            if (i == int(log2(N, 2) - 1 and realMax-1 < idxList.size()))
            {
                vector<int> idxs{&idxList[i * logN], &idxList[idxList.size()]};
                that = getMaxIndex(idxs);
                break;
            }
            else if (realMax - 1 < i * logN + logN)
            {
                vector<int> idxs{&idxList[i * logN], &idxList[i * logN + logN]};
                that = getMaxIndex(idxs);
                break;
            }
    }
    box_report(that);
}