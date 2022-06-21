#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dp[101][1100];
int bigCost[101];
int lastIndex[101];
typedef struct schedule {
	int b;
	int e;
	int c;
}schedule;
schedule* table;

bool compare(const schedule s1, const schedule s2) {
	if (s1.b == s2.b) {
		if (s1.e == s2.e) return s1.c >= s2.c;
		else return s1.e < s2.e;
	}
	else  return s1.b < s2.b;
}

void dpSet(int tableIndex, bool check, int dpIndex = 0) {
	if (!check) {
		for (int j = table[tableIndex].b; j <= table[tableIndex].e; j++) {
			dp[tableIndex][j] = table[tableIndex].c;
			bigCost[tableIndex] = table[tableIndex].c;
		}
	}	
	else {
		int findBig = dp[dpIndex][lastIndex[dpIndex]];
		if (max(bigCost[tableIndex], findBig + table[tableIndex].c - 10) != bigCost[tableIndex]) {
			bigCost[tableIndex] = findBig + table[tableIndex].c - 10;
			copy(dp[dpIndex], dp[dpIndex] + lastIndex[dpIndex]+1, dp[tableIndex]);
			for (int j = table[tableIndex].b; j <= table[tableIndex].e; j++) {
				dp[tableIndex][j] = bigCost[tableIndex];
			}
		}
	}
	lastIndex[tableIndex] = table[tableIndex].e;
}
void solveLast() {
	int bigOfbig = 0;
	int bigIndex = 0;
	int workDay[100] = { 0, };
	for (int i = 1; i <= N; i++) {
		if (bigOfbig == bigCost[i]) {
			if (workDay[bigIndex] == 0) {
				for (int j = 1; j <= lastIndex[bigIndex]; j++)
					if (dp[bigIndex][j] != 0) workDay[bigIndex]++;
			}
			for (int j = 1; j <= lastIndex[bigIndex]; j++) if (dp[i][j] != 0) workDay[i]++;
			if (workDay[bigIndex] > workDay[i]) bigIndex = i;
		}
		else if (bigOfbig < bigCost[i]) {
			bigOfbig = bigCost[i];
			bigIndex = i;
		}
	}
	if (workDay[bigIndex] == 0) {
		for (int j = 1; j <= lastIndex[bigIndex]; j++) 
			if (dp[bigIndex][j] != 0) workDay[bigIndex]++;
	}
	cout << bigOfbig << " " << workDay[bigIndex] << endl;
}

void solve() {
	dpSet(1,false);
	for (int i = 2; i <= N; i++) {
		for (int k = 1; k < i; k++) {
			int begin = table[i].b;
			int end = table[i].e;
			int pos = 0;
			for (pos = begin; pos <= end; pos++) 
				if (dp[k][pos] != 0) break;
			if (pos == end + 1) dpSet(i, true,k);
		}
		if (bigCost[i] == 0) dpSet(i,false);
	}
	solveLast();
}

int main() {
	cin >> N;
	table = new schedule[N+1];
	for (int i = 1; i <= N; i++) {
		cin >> table[i].b >> table[i].e >> table[i].c;
	}
	sort(table+1, table + N+1, compare);
	solve();
	delete []table;
}