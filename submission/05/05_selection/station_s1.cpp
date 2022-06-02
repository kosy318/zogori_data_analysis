#include <bits/stdc++.h>
using namespace std;

struct P { 
    double x, y ,z;
    P(double x=0, double y=0, double z=0) : x{x}, y{y}, z{z} {}
}; 
P A,B,C,D,T;
double temp, minLen = DBL_MAX;

auto isNegligible = [](double &a, double b){ return abs(a-b) < DBL_EPSILON; };
auto getMidP = [](P &i, P &j){ return P{(i.x+j.x)/2, (i.y+j.y)/2, (i.z+j.z)/2}; };
auto getLen2 = [](P &p, P& t){ return pow(p.x-t.x,2) + pow(p.y-t.y,2) + pow(p.z-t.z,2); };

P getMinP(P &head, P &tail, P &T) {
    P mid = getMidP(head, tail);
    vector<double> lens{ getLen2(head, T), getLen2(mid, T), getLen2(tail, T), minLen };
    minLen = *min_element(lens.begin(), lens.end());
    if(isNegligible(lens[0], lens[2])) return T = mid;
    if(lens[0] > lens[2]) return getMinP(mid, tail, T);
    else return getMinP(head, mid, T);
}

int main() {
    cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z
        >> C.x >> C.y >> C.z >> D.x >> D.y >> D.z;
    T = C;
    do {
        temp = minLen;
        getMinP(A, B, T);
        getMinP(C, D, T);
    } while(!isNegligible(minLen,temp));

    minLen = sqrt(minLen);
    if(abs(minLen - floor(minLen)) > 1.0e-5) minLen++;
    cout << (int)minLen;
}