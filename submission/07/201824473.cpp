#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Work {
	int s;
	int e;
	int c;
	int period;
	vector<int> unoverlaped;
	Work(int s, int e, int c) {
		this->s = s;
		this->e = e;
		this->c = c;
		this->period = e - s + 1;
	}
	bool operator<(const Work adj) const {
		if (this->s == adj.s) {
			return this->e > adj.e;
		}
		else {
			return this->s > adj.s;
		}
	}
};

class Plan {
private:
	int N;
	vector<Work> works;
public:
	Plan(int N) : N(N) {}
	void addWork(int s, int e, int c) {
		works.push_back(Work(s, e, c-10));
	}
	void putUnOverlaped(void) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (!isOverlaped(works[i], works[j])) {
					works[i].unoverlaped.push_back(j);
				}
			}
		}
	}
	bool isOverlaped(Work a, Work b) {
		return (a.s <= b.s && b.s <= a.e) ||
			(a.s <= b.e && b.e <= a.e) ||
			(b.s <= a.s && a.e <= b.e);
	}
	void getResult() {
		vector<vector<int>> maxC, minP;
		vector<int> tmpC, tmpP;
		tmpC.push_back(0); tmpC.push_back(works[0].c + 10);
		tmpP.push_back(0); tmpP.push_back(works[0].period);
		maxC.push_back(tmpC);
		minP.push_back(tmpP);
		for (int i = 1; i < N; i++) {
			int doC, ornotC;
			int doP, ornotP;

			if (maxC[i-1][0] > maxC[i-1][1]) {
				ornotC = maxC[i-1][0];
				ornotP = minP[i-1][0];
			} else if (maxC[i-1][0] < maxC[i-1][1]) {
				ornotC = maxC[i-1][1];
				ornotP = minP[i-1][1];
			} else {
				if (minP[i-1][0] < minP[i-1][1]) {
					ornotC = maxC[i-1][0];
					ornotP = minP[i-1][0];
				} else {
					ornotC = maxC[i-1][1];
					ornotP = minP[i-1][1];
				}
			}

			if (works[i].unoverlaped.empty()) {
				doC = works[i].c + 10;
				doP = works[i].period;
			} else {
				int maxIdx = 0;
				for (int j = 0; j < works[i].unoverlaped.size(); j++) {
					if (maxC[works[i].unoverlaped[j]][1] > maxC[works[i].unoverlaped[maxIdx]][1])
						maxIdx = j;
				}
				doC = maxC[works[i].unoverlaped[maxIdx]][1] + works[i].c;
				doP = minP[works[i].unoverlaped[maxIdx]][1] + works[i].period;
			}
			vector<int> tmpC0, tmpP0;
			tmpC0.push_back(ornotC); tmpC0.push_back(doC);
			tmpP0.push_back(ornotP); tmpP0.push_back(doP);
			maxC.push_back(tmpC0);
			minP.push_back(tmpP0);
		}
		if (maxC[N-1][0] > maxC[N-1][1])
			printf("%d %d\n", maxC[N-1][0], minP[N-1][0]);
		else if (maxC[N-1][0] < maxC[N-1][1])
			printf("%d %d\n", maxC[N-1][1], minP[N-1][1]);
		else {
			if (minP[N-1][0] < minP[N-1][1])
				printf("%d %d\n", maxC[N-1][0], minP[N-1][0]);
			else
				printf("%d %d\n", maxC[N-1][1], minP[N-1][1]);
		}
	}
};

int main(void) {
	int N;
	cin >> N;
	Plan plan = Plan(N);
	priority_queue<Work> pq;
	for (int i = 0; i < N; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		pq.push(Work(s, e, c));
	}
	while (!pq.empty()) {
		plan.addWork(pq.top().s, pq.top().e, pq.top().c);
		pq.pop();
	}
	plan.putUnOverlaped();
	plan.getResult();
	return 0;
}
