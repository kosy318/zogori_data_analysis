#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef struct {
	int profit;
	int due;
}work;

int check[5][10]{};
vector<int> worknum;
vector<int> s;
vector<work> vec;
vector<work> tmp;


bool cmp(work f, work s) {
	if (f.profit == s.profit) {
		return f.due > s.due;
	}
	else return f.profit > s.profit;
}

bool compare(int f, int s) {
	return f > s;
}

int best(vector<work>vec, int k, int c, int passprofit) {
	int maximal = 0, exit=0;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < vec.size(); i++) {
		if (passprofit == vec[i].profit&&c==2) continue;
		int d = vec[i].due-1;
		while (d >=0) {
			for (int j = 0; j < k; j++) {
				if (check[j][d]==0) {
					maximal += vec[i].profit;
					check[j][d] = 1;
					if(c==1) worknum.push_back(i);
					exit = 1;
					break;
				}
			}
			if (exit == 1) break;
			d--;
		}
		exit = 0;
	}
	return maximal;
}

void solve(int k) {
	int maximal = best(vec, k, 1, 0), smaximal=0;
	for (int i = worknum.size()-1; i>=0; i--) {
		tmp = vec;
		tmp.erase(begin(tmp) + worknum[i]);
		s.push_back(best(tmp, k, 0, vec[worknum[i]].profit));
		s.push_back(best(vec, k, 2, vec[worknum[i]].profit));
	}
	
	sort(begin(s), end(s), compare);
	for (int i = 0; i < s.size(); i++) {
		smaximal = s[i];
		if (maximal > smaximal) break;
	}
	cout << maximal << " " << smaximal;
}

int main() {
	int N, T, k;
	cin >> N >> T >> k;
	for (int i = 0; i < N; i++) {
		int profit, due;
		cin >> profit >> due;
		vec.push_back({ profit,due });
	}
	sort(begin(vec), end(vec), cmp);
	solve(k);
}