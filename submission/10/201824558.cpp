#include <iostream>
#include <algorithm>

using namespace std;

class job {
private:
	int i;
	int p;
	int d;
	bool picked;
public:
	job(int profit, int due) : p(profit), d(due), picked(false) {}
	int profit() {
		return p;
	}
	int due() {
		return d;
	}
	int index() {
		return i;
	}
	void setindex(int idx) {
		i = idx;
	}
	void set() {
		picked = true;
	}
	bool isPicked() {
		return picked;
	}
};

bool compare(job* a, job* b) {
	if (a->profit() == b->profit())
		return a->due() > b->due();
	return a->profit() > b->profit();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, T, k;
	int i = 0, p, d;
	int maxProfit = 0;
	int minProfit = 0;

	job*** machine;
	job** jobList;
	cin >> N >> T >> k;

	jobList = new job * [N];
	machine = new job * *[k];
	for (int i = 0; i < k; i++) {
		machine[i] = new job * [T];
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < T; j++) {
			machine[i][j] = NULL;
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> p >> d;
		jobList[i] = new job(p, d);
	}

	sort(jobList, jobList + N, compare);

	for (int i = 0; i < N; i++) {
		jobList[i]->setindex(i);
	}

	for (int i = 0; i < N; i++) {
		bool isFilled = false;
		for (int j = jobList[i]->due() - 1; j >= 0; j--) {
			for (int l = 0; l < k; l++) {
				if (machine[l][j] == NULL) {
					machine[l][j] = jobList[i];
					jobList[i]->set();
					isFilled = true;
					break;
				}
			}
			if (isFilled)
				break;
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < T; j++) {
			if (machine[i][j] != NULL)
				maxProfit += machine[i][j]->profit();
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < T; j++) {
			if (machine[i][j] != NULL) {
				for (int l = machine[i][j]->index() + 1; l < N; l++) {
					if (jobList[l]->due() >= j + 1 && !jobList[l]->isPicked() && jobList[l]->profit() != machine[i][j]->profit()) {
						if (minProfit < maxProfit - (machine[i][j]->profit() - jobList[l]->profit()))
							minProfit = maxProfit - (machine[i][j]->profit() - jobList[l]->profit());
						break;
					}
				}
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		if (jobList[i]->isPicked()) {
			if (minProfit < maxProfit - jobList[i]->profit())
				minProfit = maxProfit - jobList[i]->profit();
			break;
		}
	}

	cout << maxProfit << " " << minProfit << endl;

}