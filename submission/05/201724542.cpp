#include <bits/stdc++.h>
#define EPS 1.0e-8
using namespace std;

typedef struct Point{
    double x, y, z;
    Point() { x = y = z = 0;}
    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
} Point;

Point getMiddlePoint(Point &p1, Point &p2) {
    double x = (p1.x + p2.x) / 2;
    double y = (p1.y + p2.y) / 2;
    double z = (p1.z + p2.z) / 2;
    return Point(x, y, z);
}

typedef struct Station {
    Point start, end, candidate;
    Station() {}
    Station(Point start, Point end) {
        this->start = start;
        this->end = end;
        this->candidate = getMiddlePoint(start, end);
    }
} Station;

double getDistance(Point &p1, Point &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

double getShortestDistance(Station &source, Station &target) {
    Point standard = source.candidate;
    Point middle = getMiddlePoint(target.start, target.end);
    Point left = target.start;
    Point right = target.end;
    
    double distanceToLeft = getDistance(standard, left);
    double distanceToRight = getDistance(standard, right);
    double distanceToMiddle = getDistance(standard, middle);
    
    while(abs(distanceToLeft - distanceToRight) >= EPS) {
        if (distanceToLeft < distanceToRight && distanceToLeft < distanceToMiddle) {
            right = middle;
        } else if (distanceToRight < distanceToLeft && distanceToRight < distanceToMiddle) {
            left = middle;
        } else {
            if (distanceToLeft < distanceToRight) {
                right = middle;
            } else {
                left = middle;
            }
        }
        middle = getMiddlePoint(left, right);
        distanceToLeft = getDistance(standard, left);
        distanceToRight = getDistance(standard, right);
        distanceToMiddle = getDistance(standard, middle);
    }
    target.candidate = middle;
    return getDistance(standard, target.candidate);
}

int main(void) {
    double x1, x2, y1, y2, z1, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    Station stationA = Station(Point(x1, y1, z1), Point(x2, y2, z2));
    
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    Station stationB = Station(Point(x1, y1, z1), Point(x2, y2, z2));

    double beforeDistance = 0;
    double currentDistance = -1;
    bool stationAFlag = true;
    while(abs(currentDistance - beforeDistance) >= EPS) {
        beforeDistance = currentDistance;
        if (stationAFlag) {
            currentDistance = getShortestDistance(stationA, stationB);
        }
        else {
            currentDistance = getShortestDistance(stationB, stationA);
        }
        stationAFlag = !stationAFlag;
    }
    if (currentDistance - ((double) int(currentDistance)) < EPS) {
        cout << int(currentDistance);
    }
    else {
        cout << int(currentDistance) + 1;
    }
    return 0;
}
