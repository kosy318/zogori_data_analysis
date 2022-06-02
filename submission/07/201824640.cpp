#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int start, end, pay;
} P;

bool cmp(const P& p1, const P& p2) {
	if (p1.start == p2.start)
		return p1.end < p2.end;
	return p1.start < p2.start;
}

bool cmp2(const P& p1, const P& p2) {
	if (p1.pay == p2.pay)
		return p1.start < p2.start;
	return p1.pay > p2.pay;
}

void print(vector<P> v, vector<P> vv) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (vv[j].end < v[i].start and (vv[i].pay < vv[j].pay + v[i].pay - 10 
				or vv[i].pay == vv[j].pay + v[i].pay - 10 
				and vv[i].start > vv[j].start + v[i].end - v[i].start + 1)) {
				vv[i].start = vv[j].start + v[i].end - v[i].start + 1;
				vv[i].end = v[i].end;
				vv[i].pay = vv[j].pay + v[i].pay - 10;
			}
		}
	}

	sort(vv.begin(), vv.end(), cmp2);
	cout << vv[0].pay << " " << vv[0].start << endl;
}

int main() {
	vector<P> v;
	vector<P> vv;
	P ps;
	int max;

	cin >> max;
	for (int i = 0; i < max; i++) {
		cin >> ps.start >> ps.end >> ps.pay;
		v.push_back(ps);
	}

	sort(v.begin(), v.end(), cmp);

	vv = v;
	for (int i = 0; i < max; i++) {
		vv[i].start = vv[i].end - vv[i].start + 1;
	}

	print(v, vv);

	return 0;
}