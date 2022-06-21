#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int* n1, int* n2) {
	if (n1[0] == n2[0])
		return n1[1] < n2[1];
	return n1[0] < n2[0];
}

int max(int n1, int n2) {
	if (n1 > n2)
		return n1;
	else
		return n2;
}


pair<int, int> max_value(vector<int*> list) {
	int* table = new int[list.size()];
	int workday = 0;
	vector<int*> newlist;
	table[0] = list[0][2];
	workday = list[0][1] - list[0][0] + 1;
	if (list.size() == 1) {
		return make_pair(table[0], workday);
	}

	if (list[1][0] > list[0][1]) {
		workday += list[1][1] - list[1][0] + 1;
		table[1] = table[0] + list[1][2];
	}
	else if (list[1][0] <= list[0][1] && list[0][2] < list[1][2]) {
		workday = list[1][1] - list[1][0] + 1;
		table[1] = list[1][2];
	}
	else {
		table[1] = table[0];
	}

	if (list.size() == 2)
		return make_pair(table[1], workday);

	for (int i = 2; i < list.size(); i++) {
		newlist.clear();
		for (int j = 0; j < i; j++) {
			if (list[j][1] < list[i][0])
				newlist.push_back(list[j]);
		}
		if (newlist.size() == 0) {
			if (table[i - 1] > list[i][2]) {
				table[i] = table[i - 1];
			}
			else if (table[i - 1] < list[i][2]) {
				table[i] = list[i][2];
				workday = list[i][1] - list[i][0] + 1;
			}
			else {
				table[i] = table[i - 1];
				workday = (workday < list[i][1] - list[i][0] + 1) ? workday : list[i][1] - list[i][0] + 1;
			}
		}
		else {
			pair<int, int> result_from_newlist = max_value(newlist);
			if (table[i - 1] > list[i][2] + result_from_newlist.first - 10) {
				table[i] = table[i - 1];
			}
			else if (table[i - 1] < list[i][2] + result_from_newlist.first - 10) {
				table[i] = list[i][2] + result_from_newlist.first - 10;
				workday = list[i][1] - list[i][0] + 1 + result_from_newlist.second;
			}
			else {
				table[i] = table[i - 1];
				workday = (workday < list[i][1] - list[i][0] + 1 + result_from_newlist.second) ? workday : list[i][1] - list[i][0] + 1 + result_from_newlist.second;
			}
		}
	}

	return make_pair(table[list.size() - 1], workday);
}

int main()
{
	int N;
	int* input;
	vector<int*> cleaning_list;

	scanf("%d", &N);


	for (int i = 0; i < N; i++) {
		input = new int[3];
		scanf("%d %d %d", &input[0], &input[1], &input[2]);
		cleaning_list.push_back(input);
	}


	sort(cleaning_list.begin(), cleaning_list.end(), comp);

	pair<int, int> result = max_value(cleaning_list);

	printf("%d %d", result.first, result.second);
	return 0;
}