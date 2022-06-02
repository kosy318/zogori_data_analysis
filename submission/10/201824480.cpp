#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int N, T, k;
int workfield[6][31] = {0, };
bool loopflag;
int sum = 0;

struct work {
	int c, d;
	bool used;
};
vector<work> wv;

bool cmp(const work& a, const work& b) {
	return a.c > b.c;
}

int main() {
	cin >> N >> T >> k;
	int cinput, dinput;
	for (int i = 0; i < N; i++) {
		cin >> cinput >> dinput;
		wv.push_back({ cinput, dinput, false });
	}
	sort(wv.begin(), wv.end(), cmp);
	int min = 987654321;
	for (int w = 0; w < wv.size(); w++) {
		loopflag = false;
		for (int i = wv[w].d; i >= 1; i--) {
			for (int j = 1; j <= k; j++) {
				if (workfield[j][i])
					continue;
				workfield[j][i] = wv[w].c;
				min = min > workfield[j][i] ? workfield[j][i] : min;
				sum += wv[w].c;
				loopflag = true;
				wv[w].used = true;
				break;
			}
			if (loopflag) break;
		}
	}
	int min1 = 987654321;
	int min2 = 987654321;
	for (auto w : wv) {
		if (w.used)
			continue;
		for (int i = w.d; i >= 1; i--) {
			for (int j = 1; j <= k; j++) {
				if (min1 > workfield[j][i]) 
					min1 = workfield[j][i];
			}
		}
		if (min1 - w.c < min2 && min1 != w.c) {
			min2 = min1 - w.c;
		}
	}
	int finalmin = min > min2 ? min2 : min;
	cout << sum << " " << sum - finalmin;
}