#include "timebomb.h"
#include <bits/stdc++.h>
using namespace std;

void find_max(queue<int>& Q, vector<pair<int, int>>& vp) {
	int result;

	while(Q.size() > 1) {
		int i = Q.front();
		Q.pop();
		int j = Q.front();
		Q.pop();

		result = box_comp(i, j);
		switch(result) {
			case 1: {
				vp.push_back(make_pair(i, j));
				Q.push(i);
				break;
			}
			case -1: {
				vp.push_back(make_pair(j, i));
				Q.push(j);
				break;
			}
		}
	}
}

int operating(int num) {
	int t;
	queue<int> Q;
	vector<pair<int, int>> vp;

	for(int i = 1; i <= num; i++) { Q.push(i); }

	find_max(Q, vp);

	for(auto p : vp) {
		if (p.first == Q.front()) { Q.push(p.second); }
	}
	Q.pop();

	find_max(Q, vp);
	t = Q.front();

	return t;
}

int main() {
	int num, t;
	box_ready();
	num = box_size();
	t = operating(num);
	box_report(t);
	return 0;
}
