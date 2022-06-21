#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "timebomb.h"
using namespace std;

int cmp_first(vector<int>& vec1, vector<vector<int>>& smaller) {
	int size1 = vec1.size();

	if (size1 == 1) { return vec1[0]; }
	if (size1 == 2) {
		if (box_comp(vec1[0]+1, vec1[1]+1) == 1) { smaller[vec1[0]].push_back(vec1[1]); return vec1[0]; }
		else { smaller[vec1[1]].push_back(vec1[0]); return vec1[1]; }
	}

	int big, small;
	vector<int> bigger;

	for (int i = 0; i < size1; i++) {

		if (i%2 == 0 && i == size1-1) { bigger.push_back(vec1[i]); break; }
		if (i%2 != 0) { continue; }

		if (box_comp(vec1[i] + 1, vec1[i+1] + 1) == 1) { big = vec1[i  ]; small = vec1[i+1]; }
		else { big = vec1[i+1]; small = vec1[i  ]; }

		bigger.push_back(big);		smaller[big].push_back(small);

	}
	return cmp_first(bigger, smaller);
}


int cmp_second(vector<int>& vec2, vector<vector<int>>& smaller) {
	int size2 = vec2.size();

	if (size2 == 1) { return vec2[0]; }
	if (size2 == 2) { return (box_comp(vec2[0]+1, vec2[1]+1) == 1) ? vec2[0] : vec2[1]; }

	int big, small;
	vector<int> bigger;

	for (int i = 0; i < size2; i++) {
		
		if (i%2 == 0 && i == size2-1) {  bigger.push_back(vec2[i]); break; }
		if (i%2 != 0) { continue; }

		if (!smaller[vec2[i]].empty()) {
			vector<int>::iterator it1 = find(smaller[vec2[i]].begin(), smaller[vec2[i]].end(), vec2[i + 1]);
			if (it1 != smaller[vec2[i]].end()) { bigger.push_back(vec2[i]); continue; }
		}
		if (!smaller[vec2[i+1]].empty()) {
			vector<int>::iterator it2 = find(smaller[vec2[i + 1]].begin(), smaller[vec2[i + 1]].end(), vec2[i]);
			if (it2 != smaller[vec2[i + 1]].end()) { bigger.push_back(vec2[i + 1]); continue; }
		}

		if (box_comp(vec2[i] + 1, vec2[i+1] + 1) == 1) { big = vec2[i]; small = vec2[i+1]; }
		else { big = vec2[i+1]; small = vec2[i]; }
		bigger.push_back(big); smaller[big].push_back(small);
	}
	return cmp_second(bigger, smaller);
}



int main() {

	box_ready();
	int N = box_size();

	vector<int> vec, temp;
	vector<vector<int>> smaller;

	for (int i = 0; i < N; i++) { vec.push_back(i); smaller.push_back(temp); }
	int max = cmp_first(vec, smaller);
	int _this = cmp_second(smaller[max], smaller);
	box_report(_this + 1);

	return 0;
}