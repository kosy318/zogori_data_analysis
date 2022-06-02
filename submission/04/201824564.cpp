#include <bits/stdc++.h>
#include "timebomb.h"

using namespace std;

const int maxN = 5010;
int box_N;

vector < vector <int> > Compare_log(maxN);
queue <int> Box_queue;

int findMaxBox() {
	int max_box, result;
	while (Box_queue.size() != 1) {
		int boxA = Box_queue.front(); Box_queue.pop();
		int boxB = Box_queue.front(); Box_queue.pop();
		
		result = box_comp(boxA, boxB);
	
		// box_comp()후 작은 쪽의 인덱스를 큰 쪽의 Compare_log에 삽입
		if (result == 1) {
			Compare_log[boxA].push_back(boxB);
			Box_queue.push(boxA);
			max_box = boxA;
		}
		else if (result == -1) {
			Compare_log[boxB].push_back(boxA);
			Box_queue.push(boxB);
			max_box = boxB;
		}
	}
    Box_queue.pop();
	return max_box;
}

int main() {
	int max_box, answer;
	
	box_ready();
	box_N = box_size();

	// start
	for (int i = 1; i <= box_N; i++) Box_queue.push(i);	
	max_box = findMaxBox();

	// max_box와 box_comp()했던 인덱스들 중 가장 큰 값 추출
	for (auto& box : Compare_log[max_box]) Box_queue.push(box);
	answer = findMaxBox();

	box_report(answer);
}

