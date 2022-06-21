#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int N, T, K;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.first < b.first;
	}
};
priority_queue<int> work[11];
priority_queue <int> not_machine[11];
priority_queue<int, vector<int>, greater<int>> in_machine[11];
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> comparing;

bool isfull(int n) {
	for (int i = 1; i <= n; ++i) {
		if (in_machine[i].size() != K) {
			return false;
		}
	}
	return true;
}

void set() {
	cin >> N >> T >> K;

	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		work[b].push(a);
	}

	for (int i = 1; i <= T; ++i) {
		if (!work[i].empty()) {
			int max = work[i].top();
			work[i].pop();
			comparing.push({ max, i });
		}
	}
}

void build() {
	while (!comparing.empty()) {
		pair<int, int> max = comparing.top();
		if (!isfull(max.second)) {
			int i = max.second;
			while (i >= 1) {
				if (in_machine[i].size() != K) {
					in_machine[i].push(max.first);
					break;
				}
				--i;
			}
		}
		else {
			not_machine[max.second].push(max.first);
		}

		comparing.pop();
		if (!work[max.second].empty()) {
			comparing.push({ work[max.second].top(), max.second });
			work[max.second].pop();
		}
	}
}
void print() {

	int min = 101;
	for (int i = 1; i <= T; ++i) {
		if (!not_machine[i].empty()) {
			int max_at_i = not_machine[i].top();
			for (int j = i; j >= 1; --j) {
				int m = in_machine[j].top();
				if (min > m - max_at_i && m - max_at_i != 0)
					min = m - max_at_i;
			}
		}
	}
	for (int i = 1; i <= T; ++i) {
		if (!in_machine[i].empty()) {
			int max_at_i = in_machine[i].top();
			if (min > max_at_i)
				min = max_at_i;
		}
	}



	int sum = 0;
	for (int i = 1; i <= T; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (!in_machine[i].empty()) {
				sum += in_machine[i].top();
				if (!in_machine[i].empty())
					in_machine[i].pop();
			}
		}
	}

	cout << sum << ' ' << sum - min;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	set();
	build();
	print();

	return 0;
}

