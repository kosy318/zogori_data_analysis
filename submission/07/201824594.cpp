#include <iostream>
#include <algorithm>

using namespace std;

int N;

struct work {
	int begin;
	int end;
	int cost;

	friend istream& operator >>(istream& is, work& w) {
		is >> w.begin;
		is >> w.end;
		is >> w.cost;
		return is;
	}
};

bool compare(work a, work b) {
	if (a.end == b.end)
		if (a.begin == b.begin) {
			return a.cost < b.cost;
		}
		else {
			return a.begin < b.begin;
		}
	return a.end < b.end;
}

work labor[101];
int cost_sum[365*3+1];
int date_sum[365*3+1];


int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	 

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> labor[i];
	}
	sort(labor+1, labor + N+1, compare);

	int end = labor[N].end;

	fill(cost_sum + labor[1].end, cost_sum + end + 1, labor[1].cost);
	fill(date_sum + labor[1].end, date_sum + end + 1, labor[1].end - labor[1].begin + 1);


	for (int i = 2; i <= N; ++i) {
		int b = labor[i].begin;
		int e = labor[i].end;
		int cost = labor[i].cost;
		if (cost_sum[b - 1] == 0) {
			if (cost_sum[e] < cost) {
				fill(cost_sum + e, cost_sum + end + 1, cost);
				fill(date_sum + e, date_sum + end + 1, e - b + 1);
			}
			else if (cost_sum[e] == cost) {
				if (date_sum[e] > e - b + 1)
					fill(date_sum + e, date_sum + end + 1, e - b + 1);
			}
		}
		else {
			if (cost_sum[e] < cost_sum[b - 1] + cost - 10) {
				fill(cost_sum + e, cost_sum + end + 1, cost_sum[b - 1] + cost - 10);
				fill(date_sum + e, date_sum + end + 1, date_sum[b - 1] + e - b + 1);
			}
			else if (cost_sum[e] == cost_sum[b - 1] + cost - 10) {
				if (date_sum[e] > date_sum[b - 1] + e - b + 1)
					fill(date_sum + e, date_sum + end + 1, date_sum[b - 1] + e - b + 1);
			}

		}
	}

	cout << cost_sum[end] << " " << date_sum[end];
	return 0;
}
