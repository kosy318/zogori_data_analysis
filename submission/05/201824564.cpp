#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

struct Point {
	double x, y, z;
	double dist(Point P) { return (x - P.x)*(x - P.x) + (y - P.y)*(y - P.y) + (z - P.z)*(z - P.z); }
};

Point getPoint(Point A, Point B, Point P) {
	auto f = [&](Point P1, Point P2, double t) -> Point {
		return {
			P1.x * (1 - t) + P2.x * t,
			P1.y * (1 - t) + P2.y * t,
			P1.z * (1 - t) + P2.z * t,
		};
	};

	double lo = 0, hi = 1;
	while (hi - lo > 1e-9) {
		double t1 = (lo * 2 + hi) / 3;
		double t2 = (lo + hi * 2) / 3;
		if (P.dist(f(A, B, t1)) < P.dist(f(A, B, t2))) hi = t2;
		else lo = t1;
	}

    return f(A, B, lo);
}

double getShortestDistance(Point A, Point B, Point C, Point D) {
	if (fabs(A.dist(B)) < 1e-10 && fabs(C.dist(D)) < 1e-10) return sqrt(A.dist(C));
	
	Point P = getPoint(A, B, C);
	Point Q = getPoint(A, B, D);

	return getShortestDistance(C, D, P, Q);
}

int main() {
	fastio;
	Point P[4];
	for (int i = 0; i < 4; i++) cin >> P[i].x >> P[i].y >> P[i].z;

	double answer = getShortestDistance(P[0], P[1], P[2], P[3]);
	
	if (answer - (int)answer < 1e-5) answer = floor(answer);
	else answer = ceil(answer);

	cout << answer << "\n";
}