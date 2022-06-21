#include "timebomb.h"


int accessor(int *E, int N, int idx) {
	if(idx >= N) {
		return idx-N+1;
	}

	return E[idx];
}

int cmp_idx(int *E, int N, int idx1, int idx2) {

	int E_idx1 = accessor(E, N, idx1);
	int E_idx2 = accessor(E, N, idx2);

	return box_comp(E_idx1, E_idx2)==1?E_idx1:E_idx2;
}

int main() {
	int N, result;

	box_ready();
	N = box_size();

	int heap[N] {};

	for(int idx=N-1; idx>=1; idx--) {
		heap[idx] = cmp_idx(heap, N, idx*2, idx*2+1);
	}

	int answer = 0;
	int cur = 1;
	int tmp, flag;
	
	do {
		flag = 0;
		if ( accessor(heap, N, cur) == accessor(heap, N, 2 * cur) )
			flag = 1;
		tmp = accessor(heap, N, 2 * cur + flag);
		if ( answer ) {
			if(box_comp(tmp, answer) == 1)
				answer = tmp;
		} else {
			answer = tmp;
		}
		cur = 2 * cur + (flag == 0);
			
	}while (cur < N);
	
	box_report(answer);
}