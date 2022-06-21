#include <iostream>

using namespace std;

pair<string, int> max(pair<string, int> p1, pair<string, int> p2, pair<string, int> p3, pair<string, int> p4, char c) {
	string ret = "";
	if (p1.second == 1 && (ret.size() < (p1.first+c).size() || (ret.size() == (p1.first + c).size() && (p1.first+c) < ret)))
		ret = p1.first + c;
	if (p2.second == 1 && (ret.size() < (p2.first + c).size() || (ret.size() == (p2.first + c).size() && (p2.first + c) < ret)))
		ret = p2.first+c;
	if (p3.second == 1 && (ret.size() < (p3.first + c).size() || (ret.size() == (p3.first + c).size() && (p3.first + c) < ret)))
		ret = p3.first+c;
	if (p4.second == 1 && (ret.size() < (p4.first + c).size() || (ret.size() == (p4.first + c).size() && (p4.first + c) < ret)))
		ret = p4.first+c;

	if (ret == "") {
		return make_pair(ret + c, 1);
	}
	return make_pair(ret, 1);
}

pair<string, int> max(pair<string, int> p1, pair<string, int> p2, pair<string, int> p3) {
	string ret = "";
	if (ret.size() < p1.first.size() || (ret.size() == p1.first.size() && ret > p1.first))
		ret = p1.first;
	if (ret.size() < p1.first.size() || (ret.size() == p1.first.size() && ret > p1.first))
		ret = p2.first;
	if (ret.size() < p1.first.size() || (ret.size() == p1.first.size() && ret > p1.first))
		ret = p3.first;

	return make_pair(ret, 0);
}

int main()
{
	string s1, s2;
	pair<string, int>** table;
	string res;

	cin >> s1 >> s2;

	s1 = " " + s1;
	s2 = " " + s2;

	table = new pair<string, int>*[s2.size()];
	for (int i = 0; i < s2.size(); i++) {
		table[i] = new pair<string, int>[s1.size()];
	}

	for (int i = 0; i < s1.size(); i++) {
		table[0][i] = make_pair("", 0);
	}
	for (int i = 0; i < s2.size(); i++) {
		table[i][0] = make_pair("", 0);
	}

	for (int i = 1; i < s1.size(); i++) {
		if (s2[1] == s1[i]) {
			table[1][i] = make_pair(s2[1], 1);
		}
		else
			table[1][i] = make_pair("", 0);
	}

	for (int i = 1; i < s2.size(); i++) {
		if (s1[1] == s2[i]) {
			table[i][1] = make_pair(s1[1], 1);
		}
		else
			table[i][1] = make_pair("", 0);
	}

	for (int i = 2; i < s2.size(); i++) {
		for (int j = 2; j < s1.size(); j++) {
			string temp = "";
			if (s2[i] == s1[j]) {
				table[i][j] = max(table[i - 1][j - 1], table[i - 1][j - 2], table[i - 2][j - 1], table[i - 2][j - 2], s2[i]);
			}
			else {
				table[i][j] = max(table[i-1][j-1], table[i - 1][j], table[i][j - 1]);
			}
		}
	}

	for (int i = 1; i < s2.size(); i++) {
		for (int j = 1; j < s1.size(); j++) {
			if (res.size() < table[i][j].first.size() || (res.size() == table[i][j].first.size() && res > table[i][j].first))
				res = table[i][j].first;
		}
	}

	cout << res << endl;
}