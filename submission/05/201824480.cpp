#include <iostream>
#include <cmath>
using namespace std;

struct coordinate {
	double x, y, z;
};

coordinate s1_start, s1_mid, s1_end, s2_start, s2_mid, s2_end;

double dist(coordinate a, coordinate b) {
	return (a.x - b.x)*(a.x - b.x) 
		 + (a.y - b.y)*(a.y - b.y) 
		 + (a.z - b.z)*(a.z - b.z);
}

coordinate findMinDot(coordinate from, coordinate& s, coordinate& e) {
	coordinate mid{
		(s.x + e.x) / 2,
		(s.y + e.y) / 2,
		(s.z + e.z) / 2
	};
	coordinate start{ s.x, s.y, s.z };
	coordinate end{ e.x, e.y, e.z };
	while ( dist(start,end) >= 0.000000000000001 ) {
		if (dist(from, start) < dist(from, end)) {
			end = { mid.x, mid.y, mid.z };
		}
		else {
			start = { mid.x, mid.y, mid.z };
		}
		mid = {
				(start.x + end.x) / 2,
				(start.y + end.y) / 2,
				(start.z + end.z) / 2
		};
	}
	
	return mid;
}

int main() {
	double x, y, z;
	cin >> x >> y >> z;
	s1_start.x = x; s1_start.y = y; s1_start.z = z;
	cin >> x >> y >> z;
	s1_end.x = x; s1_end.y = y; s1_end.z = z;
	cin >> x >> y >> z;
	s2_start.x = x; s2_start.y = y; s2_start.z = z;
	cin >> x >> y >> z;
	s2_end.x = x; s2_end.y = y; s2_end.z = z;

	s1_mid = {
		(s1_start.x + s1_end.x) / 2,
		(s1_start.y + s1_end.y) / 2,
		(s1_start.z + s1_end.z) / 2
	};
	s2_mid = {
		(s2_start.x + s2_end.x) / 2,
		(s2_start.y + s2_end.y) / 2,
		(s2_start.z + s2_end.z) / 2
	};
	double mindist = dist(s1_mid, s2_mid);
	double gap = 987654321;

	while (gap >= 0.00000000000001) {
		s2_mid = findMinDot(s1_mid, s2_start, s2_end);		
		s1_mid = findMinDot(s2_mid, s1_start, s1_end);

		gap = abs(mindist - dist(s1_mid, s2_mid));
		if (mindist > dist(s1_mid, s2_mid)) {
			mindist = dist(s1_mid, s2_mid);
		}
	}
	double sqrtdist = sqrt(mindist);
	if (sqrtdist - floor(sqrtdist) < 0.000001) {
		sqrtdist = floor(sqrtdist);
	}
	else
		sqrtdist = ceil(sqrtdist);
	cout << (int)sqrtdist;
}