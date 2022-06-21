#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
string S[1000][1000];

string compare(string a, string b) {
	if (a.length() < b.length())
		return b;
	else if (a.length() > b.length())
		return a;
	else {
		if (a < b)
			return a;
		return b;
	}
	return b;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	 
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; ++i) {
		S[i][i] = str[i];
	}

	for(int j=1;j<len;++j)
		for (int i = 0; i + j < len; ++i) {
			if (str[i] == str[i + j])
				S[i][i + j] = str[i] + S[i+1][i+j-1] + str[i + j];
			else
				S[i][i + j] = compare(S[i][i + j - 1], S[i + 1][i + j]);
		}

	cout << S[0][len - 1];
	return 0;
}
