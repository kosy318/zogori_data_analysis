#include <iostream>
#include <vector>
#include <queue>
#include "timebomb.h"


using namespace std;

int main(void) {
	int N, result, th;
	int** compSave;
	int max;
	int secondMaxComp1;
	int secondMaxComp2;
	queue<int> comparedWithMax;

	box_ready();
	N = box_size();

	compSave = new int* [(int)ceil(log(N) / log(2))];
	for (int i = 0; i < (int)ceil(log(N) / log(2)); i++) {
		compSave[i] = new int[(int)ceil(N / pow(2, i + 1))];
	}

	for (int i = 0; i < (int)ceil(N / 2.0); i++) {
		if (i * 2 + 1 != N) {
			result = box_comp(i * 2 + 1, i * 2 + 2);
			if (result == 1)
				compSave[0][i] = i * 2;
			else
				compSave[0][i] = i * 2 + 1;
		}
		else {
			compSave[0][i] = i * 2;
		}
	}

	for (int i = 0; i < (int)ceil(log(N) / log(2)) - 1; i++) {
		for (int j = 0; j < (int)ceil(N / pow(2, i + 1)); j+=2) {
			if (j + 1 != (int)ceil(N / pow(2, i + 1))) {
				result = box_comp(compSave[i][j]+1, compSave[i][j + 1]+1);
				if (result == 1)
					compSave[i + 1][j / 2] = compSave[i][j];
				else
					compSave[i + 1][j / 2] = compSave[i][j + 1];
			}
			else {
				compSave[i + 1][j / 2] = compSave[i][j];
			}
		}
	}
	max = compSave[(int)ceil(log(N) / log(2)) - 1][0];
	if (max % 2 == 0) {
		if (max + 1 < N)
			comparedWithMax.push(max + 1);
	}
	else
		comparedWithMax.push(max - 1);

	for (int i = 0; i < (int)ceil(log(N) / log(2)) - 1; i++) {
		for (int j = 0; j < (int)ceil(N / pow(2, i + 1)); j++) {
			if (compSave[i][j] == max) {
				if (j % 2 == 0) {
					if (j + 1 < (int)ceil(N / pow(2, i + 1)))
						comparedWithMax.push(compSave[i][j + 1]);
				}
				else
					comparedWithMax.push(compSave[i][j - 1]);
			}

		}
	}
	
	while (comparedWithMax.size() != 1) {
		secondMaxComp1 = comparedWithMax.front();
		comparedWithMax.pop();
		secondMaxComp2 = comparedWithMax.front();
		comparedWithMax.pop();
		result = box_comp(secondMaxComp1 + 1, secondMaxComp2 + 1);
		if (result == 1)
			comparedWithMax.push(secondMaxComp1);
		else
			comparedWithMax.push(secondMaxComp2);
	}
	box_report(comparedWithMax.front()+1);
	return 0;
}