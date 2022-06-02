#include <bits/stdc++.h>
using namespace std;

double calcPoweredDist(array<double, 3> P, array<double, 3> Q){
    return pow(P[0]-Q[0], 2) +  pow(P[1]-Q[1], 2) + pow(P[2]-Q[2], 2);
}
double run(array<double, 3> A, array<double, 3> B, array<double, 3> P, double t, double gap){
    double dist = calcPoweredDist(P, {A[0]*(1-t) + B[0]*t, A[1]*(1-t) + B[1]*t, A[2]*(1-t) + B[2]*t});
    double dist_before = dist;
    if(t + gap <= 1){
        dist = calcPoweredDist(P, {A[0]*(1-(t + gap)) + B[0]*(t + gap), A[1]*(1-(t + gap)) + B[1]*(t + gap), A[2]*(1-(t + gap)) + B[2]*(t + gap)});
    }
    if(t - gap >= 0){
        dist_before = calcPoweredDist(P, {A[0]*(1-(t - gap)) + B[0]*(t - gap), A[1]*(1-(t - gap)) + B[1]*(t - gap), A[2]*(1-(t - gap)) + B[2]*(t - gap)});
    }
    bool right = true;
    if(dist >= dist_before){
        right = false;
        dist = dist_before;
    }
    if(dist >= calcPoweredDist(P, {A[0]*(1-t) + B[0]*t, A[1]*(1-t) + B[1]*t, A[2]*(1-t) + B[2]*t})){return t;}
    if(!right){gap = -gap;}
    t += 2 * gap;
    while(0 <= t && t <= 1)
        {
            dist_before = dist;
            dist = calcPoweredDist(P, {A[0]*(1-t) + B[0]*t, A[1]*(1-t) + B[1]*t, A[2]*(1-t) + B[2]*t});
            if(dist >= dist_before){break;}
            t += gap;
        }
    t -= gap;
    return t;
}

int main() {
    array<double, 3> A, B, C, D;       //[x, y, z]
    cin >> A[0] >> A[1] >> A[2];
    cin >> B[0] >> B[1] >> B[2];
    cin >> C[0] >> C[1] >> C[2];
    cin >> D[0] >> D[1] >> D[2];

    double t1, t2, t1_before, t2_before, gap, temp;
    t1 = t2 = 0.5;
    t1_before = t2_before = 0;
    gap = 1/1000000.0;
    while(t1 != t1_before || t2 != t2_before){
        temp = run(A, B, {C[0]*(1-t2) + D[0]*t2, C[1]*(1-t2) + D[1]*t2, C[2]*(1-t2) + D[2]*t2}, t1, gap);
        t1_before = t1;
        t1 = temp;
        temp = run(C, D, {A[0]*(1-t1) + B[0]*t1, A[1]*(1-t1) + B[1]*t1, A[2]*(1-t1) + B[2]*t1}, t2, gap);
        t2_before = t2;
        t2 = temp;
    }
    double result = calcPoweredDist({A[0]*(1-t1) + B[0]*t1, A[1]*(1-t1) + B[1]*t1, A[2]*(1-t1) + B[2]*t1}, {C[0]*(1-t2) + D[0]*t2, C[1]*(1-t2) + D[1]*t2, C[2]*(1-t2) + D[2]*t2});
    result = sqrt(result);
    result -= gap*10000;
    cout << int(ceil(result)) ;
}