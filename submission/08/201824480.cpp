#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct stacked {
	bool is, js;
};

string LCS[101][101];
stacked ijs[101][101];
string lcq = "";
bool is, js;

string& max(string& a, string& b) {
	if (a.size() < b.size())
		return b;
	else if (a.size() == b.size()) {
		if (a < b)
			return a;
		else
			return b;
	}
	else
		return a;

}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	s1[0] == s2[0] ? LCS[1][1].push_back(s1[0]) : LCS[1][1].clear();
	for (int i = 2; i <= s1.size(); i++) {
		if (s2[0] == s1[i - 1] || s2[0] == s1[i - 2])
			LCS[i][1].push_back(s2[0]);
	}
	for (int i = 2; i <= s2.size(); i++) {
		if (s1[0] == s2[i - 1] || s1[0] == s2[i - 2])
			LCS[1][i].push_back(s1[0]);
	}
	for (int i = 2; i <= s1.size(); i++) {
		for (int j = 2; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				string temp1 = LCS[i - 1][j - 1];
				string temp2;
				if (i >= 3 && j>=3 && s1[i-3] == s2[j-3])
					temp2 = LCS[i-2][j-2];
				else 
					temp2 = "";
				temp1.push_back(s1[i - 1]);
				temp2.push_back(s1[i - 1]);
				string temp3 = ijs[i - 1][j].is ? "" : LCS[i - 1][j];
				string temp4 = ijs[i][j - 1].js ? "" : LCS[i][j - 1];

				LCS[i][j] = max(max(temp1, temp3), max(temp4, temp2));
				if (LCS[i][j] == temp1) {
					ijs[i][j].is = false;
					ijs[i][j].js = false;
				}
				else if (LCS[i][j] == LCS[i - 1][j]) {
					ijs[i][j].is = true;
					ijs[i][j].js = false;
				}
				else if (LCS[i][j] == LCS[i][j - 1]) {
					ijs[i][j].js = true;
					ijs[i][j].is = false;
				}
				else {
					ijs[i][j].is = false;
					ijs[i][j].js = false;
				}
			}
			else if (s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
				LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
				if (LCS[i][j] == LCS[i][j - 1]) {
					ijs[i][j].js = true;
					ijs[i][j].is = false;
				}
				else {
					ijs[i][j].js = false;
					ijs[i][j].is = true;
				}
			}
			else if (s1[i - 1] == s2[j - 2]) {
				if (!ijs[i][j - 1].js) {
					LCS[i][j] = LCS[i][j - 1];
				}
				else {
					LCS[i][j].push_back(s1[i - 1]);
				}

				ijs[i][j].js = true;
				ijs[i][j].is = false;
			}
			else if (s1[i - 2] == s2[j - 1]) {
				if (!ijs[i-1][j].is) {
					LCS[i][j] = LCS[i-1][j];
				}
				else {
					LCS[i][j].push_back(s2[j - 1]);
				}
				ijs[i][j].js = false;
				ijs[i][j].is = true;
			}
			else {
				if (s1[i - 2] == s2[j - 2]) {
					LCS[i][j] = LCS[i - 1][j - 1];
					ijs[i][j].js = false;
					ijs[i][j].is = false;
				}
				else {
					LCS[i][j].clear();
					ijs[i][j].js = false;
					ijs[i][j].is = false;
				}
				
			}
			
		}
	}
	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			lcq = max(lcq, LCS[i][j]);
		}
	}
	cout << lcq;
}