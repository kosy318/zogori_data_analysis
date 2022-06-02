#include <iostream>
#include <vector>

using namespace std;

vector<pair<pair<int, int>, bool>> getContinuousSet(int* arr, int len);

bool checker(vector<pair<pair<int, int>, bool>> contSet, int* fishbread) {
	if (contSet.size() == 2 && (contSet[0].second || contSet[1].second)) {
		return true;
	}
	else if (contSet.size() == 3) {
		if(contSet[0].second && contSet[1].second && !contSet[2].second && fishbread[contSet[2].first.second] == -fishbread[contSet[0].first.second] - 1 || 
		   !contSet[0].second && contSet[1].second && contSet[2].second && fishbread[contSet[0].first.first] == -fishbread[contSet[2].first.first] + 1)
			return true;
		else if (contSet[0].second && !contSet[1].second && contSet[2].second) {
			if(fishbread[contSet[0].first.first] == -fishbread[contSet[1].first.first]+1 && fishbread[contSet[2].first.second] == -fishbread[contSet[1].first.second]-1 ||
				fishbread[contSet[1].first.second] == -fishbread[contSet[0].first.second]-1 && fishbread[contSet[1].first.first] == -fishbread[contSet[2].first.first]+1)
				return true;
		}
	}
	return false;
}

int main(void) {
	int k;
	int* fishbread;
	vector<pair<pair<int, int>, bool>> contSet;

	cin >> k;

	for (int i = 0; i < 5; i++) {
		fishbread = new int[k];

		for (int j = 0; j < k; j++) {
			cin >> fishbread[j];
		}

		contSet = getContinuousSet(fishbread, k);

		if (contSet.size() == 1 && contSet[0].second)
			cout << "one" << endl;
		else if (checker(contSet, fishbread)) {
			cout << "two" << endl;
		}
		else {
			cout << "over" << endl;
		}

		delete[] fishbread;
	}
	return 0;
}

vector<pair<pair<int, int>, bool>> getContinuousSet(int* arr, int len) {
	vector<pair<pair<int, int>, bool>> contSet;
	pair<int, int> position;
	bool isMinus = arr[0] < 0;

	position.first = 0;

	for (int i = 0; i < len-1; i++) {
		if (isMinus) {
			if (arr[i] + 1 != arr[i + 1]) {
				position.second = i;
				contSet.push_back(make_pair(position, isMinus));
				if (arr[i + 1] > 0) {
					isMinus = false;
				}
				position.first = i + 1;
			}
		}
		else {
			if (arr[i] + 1 != arr[i + 1]) {
				position.second = i;
				if (!(position.first==0 && arr[position.first]==1 || position.second==len-1 && arr[position.second]==len)) {
					contSet.push_back(make_pair(position, isMinus));
				}
				position.first = i + 1;
				if (arr[i + 1] < 0) {
					isMinus = true;
				}
			}
		}
	}
	position.second = len - 1;
	if(arr[position.second] != len)
		contSet.push_back(make_pair(position, isMinus));

	return contSet;
}