#include <iostream>
#include <queue>

#include "timebomb.h"

using namespace std;

int main(void) {
	int N, result, thi;

	box_ready();
	N = box_size();

	int* compareTarget = (int*)malloc(sizeof(int) * (N + 1));
	queue<int> q;
	for (int i = 1; i <= N; i++) q.push(i);

	while (!q.empty()) {
		int compareCnt = q.size();
		int big, small;

		if (compareCnt == 1) break;

		for (int i = 0; i < compareCnt / 2; i++) {
			big = q.front();
			q.pop();
			small = q.front();
			q.pop();

			compareTarget[big] = small;
			compareTarget[small] = big;

			result = box_comp(big, small);
			if (result == -1) big = small;

			q.push(big);
		}
	}

	int max = q.front();
	q.pop();
	for (int i = 1; i <= N; i++) {
		if (compareTarget[i] == max) q.push(i);
	}
	free(compareTarget);
	while (!q.empty()) {
		int compareCnt = q.size();
		int big, small;

		if (compareCnt == 1) break;

		for (int i = 0; i < compareCnt / 2; i++) {
			big = q.front();
			q.pop();
			small = q.front();
			q.pop();

			result = box_comp(big, small);
			if (result == -1) big = small;

			q.push(big);
		}
	}
	thi = q.front();
	box_report(thi);

	return 0;
}
