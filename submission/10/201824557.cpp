#include <iostream>
#include <algorithm>

using namespace std;

struct Tasks {
	int c;
	int d;
}task[101];

int N;

int table[11][11], T, k,sum1,sum2;
bool inside[101];


void solve() {
	for (int i = 0; i < N; i++) {
		int c = task[i].c;
		int d = task[i].d-1;
		bool out = false;
		while (d >= 0 && out == false) {
			for (int j = 0; j < k; j++) {
				if (table[j][d] == 0) {
					table[j][d] = c;
					sum1 += c;
					inside[i] = true;
					out = true;
					break;
				}
			}
			d--;
		}
	}
	for (int i = 0; i < N; i++) {
		int c = task[i].c;
		int d = task[i].d;
		for (int j = 0; j < d; j++) {
			if (sum1 > sum1 + c - table[k-1][j]&& j < d && inside[i]==false) sum2 = max(sum2, sum1 + c - table[k - 1][j]);
			if (sum1 > sum1 - table[k - 1][j]) sum2 = max(sum2, sum1 - table[k - 1][j]);
		} 
	}
}

void printTable() {
	for (int i = 0; i < N; i++) cout << task[i].c << " " << task[i].d << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	cout << "sum1 : " << sum1 << endl;
	cout << "sum2 : " << sum2 << endl;
}

bool compare(const Tasks t1, const Tasks t2) {
	if (t1.c == t2.c)
		return t1.d > t2.d;
	else return t1.c > t2.c;
}

int main(void) {
	cin >> N >> T >> k;
	int c, d;
	for (int i = 0; i < N; i++) {
		cin >> c >> d;
		task[i].c = c;
		task[i].d = d;
	}
	sort(task, task + N + 1, compare);
	solve();
	cout << sum1 << " " << sum2 << endl;
	//printTable();
}