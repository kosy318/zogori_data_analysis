#include "timebomb.h"
#include <vector>

using namespace std;

int main() {
	vector<int> v[20];
	vector<int> fightList;
	int N, big, result, round=0;

	box_ready();
	N = box_size();
	for (int i = 0; i <= N; i++) {
		v[round].push_back(i);
	}
	while (true) {
		v[round+1].push_back(0);
		for (int i = 1; i < v[round].size(); i = i + 2) {
			if (i + 1 < v[round].size()) {
				result = box_comp(v[round][i], v[round][i + 1]);
			}
			else {
				result = 0;
			}
			if (result == 1) v[round+1].push_back(v[round][i]);
			else if (result == -1) v[round+1].push_back(v[round][i + 1]);
			else v[round+1].push_back(v[round][i]);
		}
		if (v[round+1].size() == 2) break;
		round++;
	}

	big = v[round+1][1];

	round++;
	while (round > 0) {
		round--;
		for (int i = 1; i < v[round].size(); i++) {
			if (v[round][i] == big) {
				if (i % 2 == 0) {
					fightList.push_back(v[round][i - 1]);
					break;
				}
				else if (i == v[round].size()-1) break;
				else {
					fightList.push_back(v[round][i + 1]);
					break;
				}
			}
		}
	}
	int second = fightList[0];
	for (int i = 1; i < fightList.size(); i++) {
		result = box_comp(fightList[i], second);
		if (result == 1) second = fightList[i];
		else if (result == -1) continue;
		else second = fightList[i];
	}
	box_report(second);
}