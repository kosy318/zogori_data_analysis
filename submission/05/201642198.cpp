#include <bits/stdc++.h>
using namespace std;
#define NUM_SPOT 4
#define DELTA 1.0e-2
#define EPSILON 1.0e-8
#define RES_EPSILON 1.0e-4
#define td tuple<double, double, double>


enum SPOT {A, B, C, D};
enum AXIS {X, Y, Z};
vector<td> vecSpot;

int compare(double numA, double numB, double e);
td getMid(td l, td r);
td getLeftBound(td l, td r);
double getDist(td p, td q);
double BS_1st(td l, td r);
double BS_2rd(td std, td l, td r);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < NUM_SPOT; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        vecSpot.push_back(make_tuple(x, y, z));
    }

    double minDist = BS_1st(vecSpot[A], vecSpot[B]);
    int resCompare = compare(minDist, floor(minDist), RES_EPSILON);
    
    if (resCompare == 0)    minDist = floor(minDist);
    cout << ceil(sqrt(minDist));
    return 0;
}

int compare(double numA, double numB, double e) {
    double diff = numA - numB;
    if (abs(diff) <= e)   return 0;
    else                  return (diff > 0 ? 1 : -1);
}

td getMid(td l, td r) {
    double midX, midY, midZ;
    midX = (get<X>(l) + get<X>(r)) / 2;
    midY = (get<Y>(l) + get<Y>(r)) / 2;
    midZ = (get<Z>(l) + get<Z>(r)) / 2;
    return make_tuple(midX, midY, midZ);
}

td getLeftBound(td l, td r) {
    double boundX, boundY, boundZ;
    boundX = DELTA * get<X>(l) + (1-DELTA) * get<X>(r);
    boundY = DELTA * get<Y>(l) + (1-DELTA) * get<Y>(r);
    boundZ = DELTA * get<Z>(l) + (1-DELTA) * get<Z>(r);
    return make_tuple(boundX, boundY, boundZ);
}

double getDist(td p, td q) {
    double distX, distY, distZ;
    distX = get<X>(p) - get<X>(q);
    distY = get<Y>(p) - get<Y>(q);
    distZ = get<Z>(p) - get<Z>(q);
    return pow(distX, 2) + pow(distY, 2) + pow(distZ, 2);
}

double BS_1st(td l, td r) {
    td mid = getMid(l, r);
    td lBound = getLeftBound(l, mid);
    double minDistM = BS_2rd(mid, vecSpot[C], vecSpot[D]);
    double minDistLB = BS_2rd(lBound, vecSpot[C], vecSpot[D]);
    int resCompare = compare(minDistM, minDistLB, EPSILON);
    if (resCompare == 0)        return minDistM;
    else if (resCompare == 1)   return BS_1st(l, mid);
    else                        return BS_1st(mid, r);
}

double BS_2rd(td std, td l, td r) {
    td mid = getMid(l, r);
    td lBound = getLeftBound(l, mid);
    double minDistM = getDist(std, mid);
    double minDistLB = getDist(std, lBound);
    int resCompare = compare(minDistM, minDistLB, EPSILON);
    if (resCompare == 0)        return minDistM;
    else if (resCompare == 1)   return BS_2rd(std, l, mid);
    else                        return BS_2rd(std, mid, r);
}