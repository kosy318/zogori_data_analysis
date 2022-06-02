#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ni1[4] = { -1,-1,-2,-2 };
int nj1[4] = { -1,-2,-1,-2 };

int ni2[4] = { -1,-2,0,0 };
int nj2[4] = { 0,0,-1,-2 };

string S, T;
vector<vector<string>> lcqs;
vector<vector<bool>> same;

void getStrings(void) {
	cin >> S >> T;
}

void findLong(int& longi, int& longj, int mode, int i, int j) {
	for (int m = 0; m < 4; m++) {
		int di, dj;
		if (mode == 1) {
			di = i + ni1[m];
			dj = j + nj1[m];
			if (same[di][dj]) {
				if (lcqs[di][dj].length() > lcqs[longi][longj].length()) {
					longi = di;
					longj = dj;
				}
				else if (lcqs[di][dj].length() == lcqs[longi][longj].length()) {
					if (lcqs[di][dj] < lcqs[longi][longj]) {
						longi = di;
						longj = dj;
					}
				}
			}
		}
		else if (mode == 2) {
			di = i + ni2[m];
			dj = j + nj2[m];

			if (lcqs[di][dj].length() > lcqs[longi][longj].length()) {
				longi = di;
				longj = dj;
			}
			else if (lcqs[di][dj].length() == lcqs[longi][longj].length()) {
				if (lcqs[di][dj] < lcqs[longi][longj]) {
					longi = di;
					longj = dj;
				}
			}
		}
	}
}

void findLCQS(void) {

	int slen, tlen;
	slen = S.length();
	tlen = T.length();

	for (int i = 0; i <= slen; i++) {
		vector<string> temp;
		for (int j = 0; j <= tlen; j++) {
			temp.push_back("");
		}
		lcqs.push_back(temp);
	}
	for (int i = 0; i <= slen; i++) {
		vector<bool> temp;
		for (int j = 0; j <= tlen; j++) {
			if (i == 0 || j == 0) temp.push_back(false);
			else {
				if (S[i - 1] == T[j - 1]) temp.push_back(true);
				else temp.push_back(false);
			}
		}
		same.push_back(temp);
	}



	for (int i = 1; i <= slen; i++) {
		for (int j = 1; j <= tlen; j++) {
			if (i == 1 || j == 1) {
				if (same[i][j]) {
					lcqs[i][j] = S[i - 1];
				}
				else {
					if (i != 1) lcqs[i][j] = lcqs[i - 1][j];
					else if (j != 1) lcqs[i][j] = lcqs[i][j - 1];
				}
			}

			else {
				if (same[i][j]) {
					int longi = i, longj = j;
					findLong(longi, longj, 1, i, j);
					lcqs[i][j] = lcqs[longi][longj] + S[i - 1];
					if (i == slen && j == tlen) {
						longi = i; longj = j;
						findLong(longi, longj, 2, i, j);
						lcqs[i][j] = lcqs[longi][longj];
					}
				}
				else {
					int longi = i, longj = j;
					findLong(longi, longj, 2, i, j);
					lcqs[i][j] = lcqs[longi][longj];
				}
			}
		}
	}
	cout << lcqs[slen][tlen] << endl;
}

int main(void) {
	getStrings();
	findLCQS();
	return 0;
}
