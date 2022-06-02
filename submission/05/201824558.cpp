#include <iostream>
#include <cmath>

using namespace std;

class point_3d {
public:
	float x;
	float y;
	float z;
public:
	point_3d() {}
	point_3d(float x, float y, float z) : x(x), y(y), z(z) {}
	void setPoint(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

float dist_3d_square(point_3d p1, point_3d p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z);
}

point_3d getMiddle(point_3d p1, point_3d p2) {
	return point_3d((p1.x + p2.x) / 2, (p1.y + p2.y) / 2, (p1.z + p2.z) / 2);
}

point_3d getShortest(point_3d fixedpoint, point_3d start, point_3d end, point_3d mid) {
	point_3d mid_front = getMiddle(start, mid);
	point_3d mid_rear = getMiddle(mid, end);
	float dist1 = dist_3d_square(mid_front, fixedpoint);
	float dist2 = dist_3d_square(mid_rear, fixedpoint);

	if (dist1 == dist2)
		return mid;
	if (dist1 < dist2)
		return getShortest(fixedpoint, start, mid, mid_front);
	else
		return getShortest(fixedpoint, mid, end, mid_rear);
}


pair<point_3d, point_3d> getShortest2(point_3d l1_start, point_3d l1_end, point_3d l1_mid, point_3d l2_start, point_3d l2_end, point_3d l2_mid) {
	point_3d shortest1 = getShortest(l2_start, l1_start, l1_end, l1_mid);
	point_3d shortest2 = getShortest(l2_end, l1_start, l1_end, l1_mid);
	float dist1 = dist_3d_square(shortest1, l2_start);
	float dist2 = dist_3d_square(shortest2, l2_end);

	if (dist1 == dist2)
		return make_pair(l2_mid, getShortest(l2_mid, l1_start, l1_end, l1_mid));

	if (dist1 < dist2)
		return getShortest2(l1_start, l1_end, l1_mid, l2_start, l2_mid, getMiddle(l2_start, l2_mid));
	else
		return getShortest2(l1_start, l1_end, l1_mid, l2_mid, l2_end, getMiddle(l2_end, l2_mid));
}

int main()
{
	int x, y, z;
	point_3d A;
	point_3d B;
	point_3d C;
	point_3d D;

	point_3d l1_mid;
	point_3d l2_mid;

	scanf("%d %d %d", &x, &y, &z);
	A.setPoint(x, y, z);
	scanf("%d %d %d", &x, &y, &z);
	B.setPoint(x, y, z);
	scanf("%d %d %d", &x, &y, &z);
	C.setPoint(x, y, z);
	scanf("%d %d %d", &x, &y, &z);
	D.setPoint(x, y, z);

	l1_mid = getMiddle(A, B);
	l2_mid = getMiddle(C, D);

	pair<point_3d, point_3d> shortestpair = getShortest2(A, B, l1_mid, C, D, l2_mid);

	printf("%d\n", (int)ceil(sqrt(dist_3d_square(shortestpair.first, shortestpair.second))));
}