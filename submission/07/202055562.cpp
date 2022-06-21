#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int start, end, pay, days;
};

vector<info> taskList;

bool cmp(info a, info b) {
	return a.start < b.start;
}

int custom(int a, int b, int i, vector<int>& day, vector<int> dp) {
	int min_day = 0;
	if (a > b) {
		day[taskList[i].start] = day[taskList[i+1].start];
		return a;
	}
	else {
		if (i == taskList.size() - 1) day[taskList[i].start] = taskList[i].days;
		else {
			if (b == dp[taskList[i+1].start]) {
				min_day = min(day[taskList[i+1].start], day[taskList[i].end + 1] + taskList[i].days);
				day[taskList[i].start] = min_day;
			}
			else 
				day[taskList[i].start] = day[taskList[i].end + 1] + taskList[i].days;
		}
		return b;
	}
}

int make(int n) {
	int start = 0, end = 0, pay = 0, last = 0;
	for (int i = 0; i < n; i++) {
		info temp;
		cin >> start >> end >> pay;
		if (last < end) 
			last = end;
		temp.start = start; 
		temp.end = end; 
		temp.pay = pay-10; 
		temp.days = end - start + 1;
		taskList.push_back(temp);
	}
	sort(taskList.begin(), taskList.end(), cmp);

	return last;
}

void pro(vector<int>& dp, vector<int>& day) {
	for (int i = taskList.size() - 1; i >= 0; i--) {
		int temp = 0;
		if (i == taskList.size() - 1) dp[taskList[i].start] = custom(dp[taskList[i].start + 1], dp[taskList[i].end + 1] + taskList[i].pay, i, day, dp);
		else {
			if (taskList[i].start == taskList[i + 1].start) {
				temp = custom(dp[taskList[i].start + 1], dp[taskList[i].end + 1] + taskList[i].pay, i, day, dp);
				if (temp > dp[taskList[i].start]) 
					dp[taskList[i].start] = temp;
			}
			else
				dp[taskList[i].start] = custom(dp[taskList[i].start + 1], dp[taskList[i].end + 1] + taskList[i].pay, i, day, dp);
		}
		if (i != 0) {
			for (int k = taskList[i - 1].start + 1; k < taskList[i].start; k++) {
				dp[k] = dp[taskList[i].start];
				day[k] = day[taskList[i].start];
			}
		}
	}
}

int main() {
	int n = 0, idx = 2000, last = 0;
	int res, res1, res2;
	cin >> n;

	last = make(n);
	vector<int> dp(last + 2);
	vector<int> day(last + 2);
	pro(dp, day);

	res1 = *max_element(dp.begin(), dp.end());
	res2 = *max_element(day.begin(), day.end());
	res = res1 +10;
	cout << res << " " << res2;
	return 0;
}
