#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct task {
	int c;
	int d;

	bool operator > (const task& other) const {
		if (c == other.c)
			return d > other.d;
		return c > other.c;
	}
};

int main() {
	int N, T, k;
	cin >> N >> T >> k;
	vector<task> tasks;
	task t;

	for (int i = 0; i < N; i++) {
		cin >> t.c >> t.d;
		tasks.push_back(t);
	}

	sort(tasks.begin(), tasks.end(), greater<task>());

	vector<vector<int>> M(k, vector<int>(T + 1, -1));
	vector<int> idxs;
	int taskIdx = 0;
	int sum = 0;
	for (auto it = tasks.begin(); it != tasks.end(); it++) {
		int d = it->d;
		int i = d;
		for (i; i > 0; i--) {
			int j = 0;
			for (j; j < k; j++) {
				if (M[j][i] == -1) {
					M[j][i] = taskIdx;
					idxs.push_back(taskIdx);
					sum += it->c;
					break;
				}
			}
			if (j != k) break;
		}
		taskIdx++;
	}
	cout << sum << " ";

	int Max = sum;
	int secondMax = 0;
	
	for (int idx = 0; idx < N; idx++) {
		auto iter = find(idxs.begin(), idxs.end(), idx);
		if (iter == idxs.end()) {
			for (int i = 0; i < k; i++) {
				for (int j = 1; j <= tasks[idx].d; j++) {
					sum = Max;
					sum -= tasks[M[i][j]].c - tasks[idx].c;
					if (sum > secondMax && sum < Max) secondMax = sum;
				}
			}
		}
		else {
			sum = Max;
			sum -= tasks[idx].c;
			if (sum > secondMax) secondMax = sum;
		}
	}
	cout << secondMax << endl;
 }