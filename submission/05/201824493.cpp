#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double m = 987654321;
double m2 = 987654321;
double midx1, midy1, midz1;

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
	return pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2);
}

class segment {
public:
	double lx, ly, lz, rx, ry, rz, midx, midy, midz;
	segment() {}
	segment(double lx1, double ly1, double lz1, double rx1, double ry1, double rz1) {
		this->lx = lx1, this->ly = ly1, this->lz = lz1, this->rx = rx1, this->ry = ry1, this->rz = rz1, this->midx = (lx1 + rx1) / 2, this->midy = (ly1 + ry1) / 2, this->midz = (lz1 + rz1) / 2;
	}
	void change(double lx1, double ly1, double lz1, double rx1, double ry1, double rz1) {
		this->lx = lx1, this->ly = ly1, this->lz = lz1, this->rx = rx1, this->ry = ry1, this->rz = rz1, this->midx = (lx1 + rx1) / 2, this->midy = (ly1 + ry1) / 2, this->midz = (lz1 + rz1) / 2;
	}
	void midchange(double midx1, double midy1, double midz1) {
		this->midx = midx1, this->midy = midy1, this->midz = midz1;
	}
};

void nnd(segment* p, double x, double y, double z) {
	double ld = dist(p->lx, p->ly, p->lz, x, y, z);
	double rd = dist(p->rx, p->ry, p->rz, x, y, z);
	double midd = dist(((p->lx+p->rx)/2), ((p->ly + p->ry) / 2), ((p->lz + p->rz) / 2), x, y, z);
	if (abs(midd - m) <= 0.00000001) {
		if (m2 > m) {
			m2 = m;
		}
		m = 987654321;
		return;
	}
	if (midd < m) { m = midd;}
	if (ld <rd) {
		p->change(p->lx, p->ly, p->lz, p->midx, p->midy, p->midz);
		nnd(p, x, y, z);
	}
	else {
		p->change(p->midx, p->midy, p->midz, p->rx, p->ry, p->rz);
		nnd(p, x, y, z);
	}
}

void nnd2(segment p[]) {
	segment p1 = p[0];
	segment p2 = p[1];
	segment tmp;
	double cc;
	double x = p2.midx, y = p2.midy, z = p2.midz;
	while (true) {
		cc = m2;
		nnd(&p1, x, y, z);
		if (abs(m2 - cc) <= 0.00000001) {
			break;
		}
		midx1 = p1.midx, midy1 = p1.midy, midz1 = p1.midz;
		p1 = p[0];
		x = midx1, y = midy1, z = midz1;
		cc = m2;
		nnd(&p2, x, y, z);
		if (abs(m2 - cc) <= 0.00000001) {
			break;
		}
		midx1 = p2.midx, midy1 = p2.midy, midz1 = p2.midz;
		p2 = p[1];
		x = midx1, y = midy1, z = midz1;
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int lx, ly, lz, rx, ry, rz;
	segment p[2];
	for (int i = 0; i < 2; i++) {
		cin >> lx >> ly >> lz >> rx >> ry >> rz;
		segment tmp(lx, ly, lz, rx, ry, rz);
		p[i] = tmp;
	}
	nnd2(p);
	
	double result = sqrt(m2);
	double final = ceil(result);
	if (result <= 0.0001) cout << 0;
	else if (result < 1) cout << 1;
	else if (result - floor(result) <= 0.00001) {
		cout << floor(result);
	}
	else cout << final << endl;{
	}
	return 0;
}