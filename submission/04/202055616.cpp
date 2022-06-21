#include "timebomb.h"
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > index_1;
vector<vector<int> > index_2;

int MAX=0;

void Time(int x,vector<vector<int> > &index) {
	int it = 0;
	
	for (int i = 0; i < (index[x].size() / 2); i++) {
		int win = box_comp(index[x][it], index[x][it + 1]);
		index.push_back(vector<int>());
		if (win == 1) index[x+1].push_back(index[x][it]);
		else index[x+1].push_back(index[x][it + 1]);
		it += 2;
	}
	if (index[x].size() % 2 == 1) index[x + 1].push_back(index[x].back());
	if (index[x + 1].size() == 1) {
		MAX = index[x + 1][0];
		return;
	}
	else {
		x++;
		Time(x,index);
	}
	return;
}

int main() {
	int N,This;

	box_ready();
	
	N = box_size();
	index_1.push_back(vector<int>());
	index_2.push_back(vector<int>());

	for (int i = 1; i <= N; i++) {
		index_1[0].push_back(i);
	}
	Time(0,index_1);

	int j = 0;

	while (!index_1[j].empty()) {
		int max_index= find(index_1[j].begin(), index_1[j].end(), MAX) - index_1[j].begin();
		if (max_index % 2 == 1) index_2[0].push_back(index_1[j][max_index - 1]);
		else if(index_1[j].size()-1 != max_index) index_2[0].push_back(index_1[j][max_index + 1]);
		j++;
	}
	
	if (index_2[0].size() != 1) Time(0, index_2);
	else MAX= index_2[0][0];
	This = MAX;

	box_report(This);
	return 0;
}