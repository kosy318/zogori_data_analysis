#include <iostream>
#include <cmath>
#include <vector>
#define ZEROPOINT 10000
#define MAXDISTANCE 40000

using namespace std;

typedef struct {
	double x;
	double y;
	double z;
} point;

double distanceFun(point p1, point p2) {
	double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
	return floor(distance * ZEROPOINT) / ZEROPOINT;
}

point centerPoint(point p1, point p2) {
	point p;
	p.x = (p1.x + p2.x) / 2;
	p.y = (p1.y + p2.y) / 2;
	p.z = (p1.z + p2.z) / 2;
	return p;
}

point shortDistancePoint(point p, point p1, point p2) {
	point centerp = centerPoint(p1, p2);
	double p1_distance = distanceFun(p1, p);
	double p2_distance = distanceFun(p2, p);
	if (p1_distance < p2_distance) {
		return shortDistancePoint(p, p1, centerp);
	}
	else if (p1_distance > p2_distance) {
		return shortDistancePoint(p, centerp, p2);
	}
	else return centerp;
}

int spaceStation(double distance, point p, point p1, point p2, point p3, point p4) {
	point short_point = shortDistancePoint(p, p1, p2);
	double current_distance = distanceFun(short_point, p);
	if (distance > current_distance) {
		return spaceStation(current_distance, short_point, p3, p4, p1, p2);
	}
	else return (int)ceil(current_distance);
}

int main() {
	vector<point> points;
	for (int i = 0; i < 4; i++) {
		double x, y, z;
		cin >> x >> y >> z;
		points.push_back({ x,y,z });
	}
	int result = spaceStation(MAXDISTANCE, points.at(0), points.at(2), points.at(3), points.at(0), points.at(1));
	cout << result;
	return 0;
}
