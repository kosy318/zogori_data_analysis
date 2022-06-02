#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define COORD_MAX 10000000.0

struct Coord {
	int x, y, z;
};
Coord A, B, C, D;
void input_coord() {
	cin >> A.x >> A.y >> A.z;
	cin >> B.x >> B.y >> B.z;
	cin >> C.x >> C.y >> C.z;
	cin >> D.x >> D.y >> D.z;
}

double calc_coord() {
	double dist = 0.0, prev_min = 0.0, cur_min = 0.0, min = COORD_MAX;
	int ratio_a_b = 0, ratio_c_d = 0;

	ratio_a_b = abs(A.x - B.x);
	if (abs(A.y - B.y) > abs(A.z - B.z)) ratio_a_b = max(abs(A.y - B.y), ratio_a_b);
	else ratio_a_b = max(abs(A.z - B.z), ratio_a_b);
	ratio_c_d = abs(C.x - D.x);
	if (abs(C.y - D.y) > abs(C.z - D.z)) ratio_c_d = max(abs(C.y - D.y), ratio_c_d);
	else ratio_c_d = max(abs(C.z - D.z), ratio_c_d);

	for (int t = 0; t < ratio_a_b + 1; t++) {
		double res_x = A.x - (double(A.x - double(B.x)) / ratio_a_b) * t;
		double res_y = A.y - (double(A.y - double(B.y)) / ratio_a_b) * t;
		double res_z = A.z - (double(A.z - double(B.z)) / ratio_a_b) * t;
		for (int e = 0; e < ratio_c_d + 1; e++) {
			double res_nx = C.x - (double(C.x - double(D.x)) / ratio_c_d) * e;
			double res_ny = C.y - (double(C.y - double(D.y)) / ratio_c_d) * e;
			double res_nz = C.z - (double(C.z - double(D.z)) / ratio_c_d) * e;

			dist = sqrt(pow((res_x - res_nx), 2) + pow((res_y - res_ny), 2) + pow((res_z - res_nz), 2));

			if (e == 0) {
				prev_min = dist;
			}
			else if (e != 0) {
				cur_min = dist;
				if (prev_min < cur_min) break;
				else prev_min = cur_min;
			}

			if (min > dist) min = dist;
		}
	}
	
	return min;
}

int main() {
	input_coord();
	cout << int(ceil(calc_coord())) << endl;
	return 0;
}