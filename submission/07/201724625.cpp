#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> quest;
int result[] = { 0, 0 };

static bool Cmp(tuple<int, int, int>& v1, tuple<int, int, int>& v2) {
	return get<1>(v1) < get<1>(v2);
}

int main() {
	int request;
	cin >> request;

	for (int i = 0; i < request; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		quest.push_back(make_tuple(start, end, cost));
	}

	sort(quest.begin(), quest.end(), Cmp);

	int final_day = get<1>(quest[request - 1]);

	int** dp = new int* [final_day + 1];
	for (int i = 0; i <= final_day; i++) {
		dp[i] = new int[2];
	}

	for (int i = 0; i <= final_day; i++) {
		dp[i][0] = 0;
		dp[i][1] = 0;
	}

	for (int i = 0; i <= final_day; i++) {
		for (int j = 0; j < quest.size(); j++) {
			if (i == get<1>(quest[j])) {
				if ((get<2>(quest[j]) + dp[get<0>(quest[j]) - 1][0] - 10 > dp[i - 1][0]) && (dp[i][0] < get<2>(quest[j]) + dp[get<0>(quest[j]) - 1][0] - 10)) {
					dp[i][0] = get<2>(quest[j]) + dp[get<0>(quest[j]) - 1][0] - 10;
					dp[i][1] = dp[get<0>(quest[j]) - 1][1] + (get<1>(quest[j]) - get<0>(quest[j]) + 1);
				}
			}
		}

		if (dp[i][0] == 0 && i != 0) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
		}
	}
	result[0] = dp[final_day][0] + 10;
	result[1] = dp[final_day][1];
	
	cout << result[0] << " " << result[1];

	return 0;
}