#include "timebomb.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, result, index;

	box_ready();
	n = box_size();
	vector<vector<int>> vec(n+1);
	vector<int> vec2(n+1);
	vector<int> vec3;
	for (int i = 0; i != n; i++) {
		vec2[i]=i+1;
	}
	int s1 = n;
	while (true) {
		for (auto i =0; i < s1; i+=2) {
			if (i + 1 >= s1) {
				vec3.push_back(vec2[i]);
			}
			else {
				int check = box_comp(vec2[i], vec2[i + 1]);
				if (check == 1) {
					vec[vec2[i]].push_back(vec2[i+1]);
					vec3.push_back(vec2[i]);
				}
				else if (check == -1) {
					vec[vec2[i+1]].push_back(vec2[i]);
					vec3.push_back(vec2[i+1]);
				}
				else break;
			}
		}
		if (vec3.size() == 1) break;
		s1 = vec3.size();
		vec2.clear();
		vec2.resize(vec3.size());
		copy(vec3.begin(), vec3.end(), vec2.begin());
		vec3.clear();
	}
	vec2.clear();
	int c = vec3[0];
	int s = vec[c].size();
	while (true) {
		for (auto i = 0; i < s; i+=2) {
			if (i + 1 >= s) {
				vec2.push_back(vec[c][i]);
			}
			else {
				int check = box_comp(vec[c][i], vec[c][i + 1]);
				if (check == 1) {
					vec2.push_back(vec[c][i]);
				}
				else if (check == -1) {
					vec2.push_back(vec[c][i + 1]);
				}
				else break;
			}
		}
		if (vec2.size() == 1) break;
		s = vec2.size();
		vec[c].clear();
		vec[c].resize(vec2.size());
		copy(vec2.begin(), vec2.end(), vec[c].begin());
		vec2.clear();
	}
	index = vec2[0];
	box_report(index);
 	return 0;
}