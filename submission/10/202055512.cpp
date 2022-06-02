#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	if (get<1>(a) == get<1>(b))
		return get<2>(a) > get<2>(b);
	else
		return get<1>(a) > get<1>(b);
}

int main() {
	int n, t, k;
	cin >> n >> t >> k;
	vector<tuple<int, int, int>> cd(n+1);
	for (int i = 1; i <= n; i++) {
		get<0>(cd[i]) = i;
		cin >> get<1>(cd[i]) >> get<2>(cd[i]);
	}
	sort(cd.begin(), cd.end(), cmp);

	int cnt = 0;
	int max_profit = 0;
	vector<vector<int>> v(t + 1, vector<int>());
	vector<int> tasks;
	for (int i = 0; i < n; i++) {
		if (cnt == k * t) break;
		int d = get<2>(cd[i]);
		for (int j = d; j > 0; j--) {
			if (v[j].size() < k) {
				v[j].push_back(get<0>(cd[i]));
				cnt++;
				max_profit += get<1>(cd[i]);
				tasks.push_back(get<0>(cd[i]));
				break;
			}
		}
	}

	int second_profit = 0;
	for (int i = 1; i <= t; i++) {
		int temp = max_profit;
		int size = v[i].size();
		if (size > 0) {
			int task = v[i][size - 1];
			int task_c = 0;
			for (int j = 0; j < n; j++) {
				if (task == get<0>(cd[j])) {
					task_c = get<1>(cd[j]);
				}
			}
			temp -= task_c;
			int new_task_c = 0;
			for (int j = 0; j < n; j++) {
				auto it = find(tasks.begin(), tasks.end(), get<0>(cd[j]));
				if (it == tasks.end()) {
					if (i <= get<2>(cd[j]) && get<1>(cd[j]) != task_c) {
						new_task_c = get<1>(cd[j]);
						break;
					}
				}
			}
			temp += new_task_c;
			if (temp > second_profit) second_profit = temp;
		}
	}

	cout << max_profit << " " << second_profit << '\n';
	return 0;
}