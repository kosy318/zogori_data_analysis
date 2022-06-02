#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> jobs;
int N, T, k;

bool compare(pair<int, int>a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first > b.first;
}

void getJobs() {
	for (int i = 0; i < N; i++) {
		int c, d;
		cin >> c >> d;
		jobs.push_back({ c,d });
	}
	sort(jobs.begin(), jobs.end(), compare);
}

void printJobs() {
	for (int i = 0; i < N; i++) {
		cout << i << ": " << jobs[i].first << " " << jobs[i].second << endl;
	}
}

void insertJob(int** sched, bool* isin, int i) {
	for (int l = jobs[i].second - 1; l >= 0; l--) {
		for (int j = 0; j < k; j++) {
			if (sched[j][l] == -1) {
				sched[j][l] = i;
				isin[i] = true;
				return;
			}
		}
	}
}

int changedJobIdx(int** sched, int i) {
	int idx = 0;
	for (int j = 0; j < k; j++) {
		for (int l = 0; l < jobs[i].second; l++) {
			if (idx < sched[j][l]) {
				idx = sched[j][l];
			}
		}
	}
	return idx;
}

void getMaximal() {
	int maximal = 0;
	int** sched;
	bool* isin;
	sched = new int* [k];
	isin = new bool[N];
	for (int i = 0; i < k; i++) {
		sched[i] = new int[T];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < T; j++) {
			sched[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		isin[i] = false;
	}

	for (int i = 0; i < N; i++) {
		insertJob(sched, isin, i);
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < T; j++) {
			if (sched[i][j] != -1)
				maximal += jobs[sched[i][j]].first;
		}
	}
	
	vector<int> second;
	for (int i = 0; i < N; i++) {
		if (!isin[i]) {
			second.push_back(maximal - (jobs[changedJobIdx(sched, i)].first - jobs[i].first));
		}
	}
	for (int i = N-1; i >= 0; i--) {
		if (isin[i]) {
			second.push_back(maximal - jobs[i].first);
			break;
		}
	}

	int sec = 0;
	for (int i = 0; i < second.size(); i++) {
		if (second[i] < maximal) {
			if (sec < second[i]) sec = second[i];
		}
	}

	/*for (int i = 0; i < k; i++) {
		for (int j = 0; j < T; j++) {
			cout << sched[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << maximal << " " << sec << endl;
}



int main(void) {
	cin >> N >> T >> k;
	getJobs();
	//printJobs();
	getMaximal();

	return 0;
}