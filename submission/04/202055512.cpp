#include "timebomb.h"
#include <vector>
#include <tuple>
using namespace std;

int main() {
	int N;
	vector<vector<tuple<int, int, int>>> tournament;
	vector<int> heavyBox, twoHeavyBox;
	box_ready();
	N = box_size();

	for (int i = 1; i <= N; i++)
		heavyBox.push_back(i);

	while (heavyBox.size() > 1) {
		vector<tuple<int, int, int>> to;
		vector<int> temp;
		int result;
		for (int i = 0; i < heavyBox.size(); i += 2) {
			if (i + 1 == heavyBox.size()) {
				temp.push_back(heavyBox[i]);
				continue;
			}
			result = box_comp(heavyBox[i], heavyBox[i + 1]);
			if (result > 0) {
				temp.push_back(heavyBox[i]);
				to.push_back({ heavyBox[i], heavyBox[i + 1], heavyBox[i] });
			}
			else if (result < 0) {
				temp.push_back(heavyBox[i + 1]);
				to.push_back({ heavyBox[i], heavyBox[i + 1], heavyBox[i + 1] });
			}
		}
		heavyBox.clear();
		for (int i = 0; i < temp.size(); i++) heavyBox.push_back(temp[i]);
		tournament.push_back(to);
	}

	int heavy = heavyBox[0];
	for (int i = 0; i < tournament.size(); i++) {
		for (int j = 0; j < tournament[i].size(); j++) {
			auto state = tournament[i][j];
			if (get<0>(state) == heavy) twoHeavyBox.push_back(get<1>(state));
			else if (get<1>(state) == heavy) twoHeavyBox.push_back(get<0>(state));
		}
	}

	while (twoHeavyBox.size() > 1) {
		vector<int> temp;
		int result;
		for (int i = 0; i < twoHeavyBox.size(); i += 2) {
			if (i + 1 == twoHeavyBox.size()) {
				temp.push_back(twoHeavyBox[i]);
				continue;
			}
			result = box_comp(twoHeavyBox[i], twoHeavyBox[i + 1]);
			if (result > 0)
				temp.push_back(twoHeavyBox[i]);
			else if (result < 0)
				temp.push_back(twoHeavyBox[i + 1]);
		}
		twoHeavyBox.clear();
		for (int i = 0; i < temp.size(); i++) twoHeavyBox.push_back(temp[i]);
	}
	box_report(twoHeavyBox[0]);
}