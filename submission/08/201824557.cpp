#include <iostream>
#include <string>

using namespace std;

string s1, s2;
string longer;

void findLonger(string tmp) {
	if (longer.length() < tmp.length()) longer = tmp;
	if (longer.length() == tmp.length()) 
		if (longer > tmp) longer = tmp;
}
void dfs(int s2_index, int s1_index,string tmp) {
	tmp += s1[s1_index];
	if (s2_index + 1 < s2.length()) {
		if (s1_index + 1 < s1.length() && s2[s2_index + 1] == s1[s1_index + 1]) dfs(s2_index + 1, s1_index + 1, tmp);
		if (s1_index + 2 < s1.length() && s2[s2_index + 1] == s1[s1_index + 2]) dfs(s2_index + 1, s1_index + 2, tmp);
	}
	
	if (s2_index + 2 < s2.length()) {
		if (s1_index + 1 < s1.length() && s2[s2_index + 2] == s1[s1_index + 1]) dfs(s2_index + 2, s1_index + 1, tmp);
		if (s1_index + 2 < s1.length() && s2[s2_index + 2] == s1[s1_index + 2]) dfs(s2_index + 2, s1_index + 2, tmp);
	}
	findLonger(tmp);
}
void solve() {
	for (int i = 0; i < s2.length(); i++)
		for (int j = 0; j < s1.length(); j++)
			if (s2[i] == s1[j]) dfs(i, j, "");
}
int main(void) {	
	cin >> s1 >> s2;
	solve();
	cout << longer << endl;
}