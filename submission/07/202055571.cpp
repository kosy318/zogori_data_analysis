#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
	int begin;
	int end;
	int cost;

	bool operator < (const Job& other) const {
		if (begin == other.begin)
			if (end == other.end) cost < other.cost;
			else return end < other.end;
		return begin < other.begin;
	}
};

int main() {
	vector<Job> jobs;

	int n, begin, end, cost;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> begin >> end >> cost;
		jobs.push_back({ begin, end, cost });
	}
	sort(jobs.begin(), jobs.end());

	vector<int> p, d, tp, td, idx;
	for (int i = 0; i < jobs.size(); i++) {
		Job job = jobs[i];
		int day;
		day = job.end - job.begin + 1;
		if (i == 0) {
			p.push_back(job.cost);
			d.push_back(day);
			tp.push_back(job.cost);
			td.push_back(day);
		}
		else {
			int pay, tmpD, tmpP;
			for (int j = i-1; j >= 0; j--) {
				if (jobs[j].end < job.begin) idx.push_back(j);
			}
			if (idx.empty()) pay = job.cost;
			else {
				auto it = idx.begin();
				tmpD = td[*it];
				int max = tp[*it];
				for (it = it + 1; it != idx.end(); it++) {
					if (tp[*it] > max) {
						max = tp[*it];
						tmpD = td[*it];
					}
				}
				idx.clear();
				if (max <= 10) pay = job.cost;
				else {
					pay = job.cost + max - 10;
					day += tmpD;
				}
			}
			tp.push_back(pay);
			td.push_back(day);
			tmpP = p[i - 1];
			
			if (pay == tmpP) {
				if (d[i - 1] < day) d.push_back(d[i - 1]);
				else d.push_back(day);
				p.push_back(pay);
			}
			else {
				int m = max(pay, tmpP);
				p.push_back(m);
				if (m == tmpP) d.push_back(d[i - 1]);
				else d.push_back(day);
			}
		}
	}
	cout << p.back() << " " << d.back() << endl;
}