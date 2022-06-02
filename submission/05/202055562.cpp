#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Coord {
	int x, y, z;
};

vector <Coord> Clist;
int main() {
	int A = 0, B = 0;

	for (int i = 0; i < 4; i++) {
		Coord temp;
		cin >> temp.x >> temp.y >> temp.z;
		Clist.push_back(temp);
	}
	
	A = abs(Clist[0].x - Clist[1].x); 
	if (abs(Clist[0].y - Clist[1].y) > abs(Clist[0].z - Clist[1].z)) 
		A = max(abs(Clist[0].y - Clist[1].y), A);
	else A = max(abs(Clist[0].z - Clist[1].z), A);
	
	B = abs(Clist[2].x - Clist[3].x);
	if (abs(Clist[2].y - Clist[3].y) > abs(Clist[2].z - Clist[3].z)) 
		B = max(abs(Clist[2].y - Clist[3].y), B);
	else B = max(abs(Clist[2].z - Clist[3].z), B);
	
	double Max = 2000000;
	
	for (int i = 0; i < A+1; i++) {
		double pre_len = 0.0, cur_len = 0.0;
		double x1 = Clist[0].x - (double((Clist[0].x) - double(Clist[1].x)) / A)*i;
		double y1 = Clist[0].y - (double((Clist[0].y) - double(Clist[1].y)) / A)*i;
		double z1 = Clist[0].z - (double((Clist[0].z) - double(Clist[1].z)) / A)*i;
		
		for (int j = 0; j < B+1; j++) {
			double x2 = Clist[2].x - (double((Clist[2].x) - double(Clist[3].x)) / B)*j;
			double y2 = Clist[2].y - (double((Clist[2].y) - double(Clist[3].y)) / B)*j;
			double z2 = Clist[2].z - (double((Clist[2].z) - double(Clist[3].z)) / B)*j;
			double temp_len = sqrt(pow((x1 - x2),2) + pow((y1 - y2),2) + pow((z1 - z2),2));
			
			if (j != 0) {
				cur_len = temp_len;
				if (pre_len < cur_len) break;
				else pre_len = cur_len;			
			}else if (j == 0) {
				pre_len = temp_len;
			}
			if (temp_len < Max) Max = temp_len;
		}
	}
	cout << int(ceil(Max)) << endl;
	return 0;
}
