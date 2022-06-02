#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	double x;
	double y;
	double z;
};

struct Line {
	Point start;
	Point end;
};

Point getMidPoint(const Point& po1, const Point& po2) {
	Point mid;
	mid.x = (po1.x + po2.x) / 2.0;
	mid.y = (po1.y + po2.y) / 2.0;
	mid.z = (po1.z + po2.z) / 2.0;
	return mid;
}

double getPointToPointLength(const Point& po1, const Point& po2) {
	double subX = po1.x - po2.x;
	double subY = po1.y - po2.y;
	double subZ = po1.z - po2.z;
	return sqrt(pow(subX, 2) + pow(subY, 2) + pow(subZ, 2));
}

double getLengthPointToLine(const Point& p, const Line& l) {
	Point start = l.start;
	Point end = l.end;
	Point mid = getMidPoint(start, end);
	double startToP = getPointToPointLength(getMidPoint(start, mid), p);
	double endToP = getPointToPointLength(getMidPoint(mid, end), p);
	double midToP = getPointToPointLength(mid, p);
	if (startToP == endToP) {
		return midToP;
	}
	else if (startToP < endToP) {
		Line temp;
		temp.start = start;
		temp.end = mid;
		return getLengthPointToLine(p, temp);
	}
	else if (startToP > endToP) {
		Line temp;
		temp.start = mid;
		temp.end = end;
		return getLengthPointToLine(p, temp);
	}
}

double getLengthBetweenLines(const Line& AB, const Line& CD) {
	Point start = AB.start;
	Point end = AB.end;
	Point mid = getMidPoint(start, end);
	double startToCD = getLengthPointToLine(getMidPoint(start, mid), CD);
	double endToCD = getLengthPointToLine(getMidPoint(mid, end), CD);
	double midToCD = getLengthPointToLine(mid, CD);

	if (startToCD == endToCD) {
		return midToCD;
	}
	else if (startToCD < endToCD) {
		Line temp;
		temp.start = start;
		temp.end = mid;
		return getLengthBetweenLines(temp, CD);
	}
	else if (startToCD > endToCD) {
		Line temp;
		temp.start = mid;
		temp.end = end;
		return getLengthBetweenLines(temp, CD);
	}
}

int main(void) {
	Point pointA, pointB, pointC, pointD;
	cin >> pointA.x >> pointA.y >> pointA.z;
	cin >> pointB.x >> pointB.y >> pointB.z;
	cin >> pointC.x >> pointC.y >> pointC.z;
	cin >> pointD.x >> pointD.y >> pointD.z;

	Line line1, line2;
	line1.start = pointA; line1.end = pointB;
	line2.start = pointC; line2.end = pointD;

	cout << (int) ceil(getLengthBetweenLines(line1, line2)) << endl;
	return 0;
}
