#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isOne(vector<int> & flip) {
	reverse(flip.begin(), flip.end());
	if (flip.size() == 1) return true;
	for (int i = 1; i < flip.size(); i++) {
		if (flip[i] - flip[i - 1] != -1) return false;
	}
	return true;
}

void isTwo(vector<int>& fish) {
	vector<int> flip;
	for (int j = 1; j < fish.size(); j++) {
		if (fish[j] != j) flip.push_back(fish[j]);
	}
	if (isOne(flip)) cout << "two" << '\n';
	else cout << "over" << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		vector<int> fish(n + 1, 0);
		vector<int> flip;
		int start = 0, start2 = 0, end = n;
		int min = 10000, max = 0;
		for (int j = 1; j <= n; j++) {
			cin >> fish[j];
			if (fish[j] != j) { 
				if (min > abs(fish[j])) { 
					start = j; 
					min = abs(fish[j]);
				}
				if (max < abs(fish[j])) {
					max = abs(fish[j]);
					start2 = j;
				}
				flip.push_back(fish[j]); 
			}
			else {
				if (end == n && start > 0) end = j - 1;
			}
		}
		if(isOne(flip)) cout << "one" << '\n';
		else {
			if (fish[start] > 0) {
				reverse(fish.begin() + start2, fish.begin() + end + 1);
				for (int j = start2; j <= end; j++)
					fish[j] = -fish[j];
				isTwo(fish);
			}
			else {
				end = abs(fish[start]);
				reverse(fish.begin() + abs(fish[start]), fish.begin() + start + 1);
				for (int j = end; j <= start; j++)
					fish[j] = -fish[j];
				isTwo(fish);
			}
		}
	}
}