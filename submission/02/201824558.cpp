#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int tIndex, count;
	int i, j;
	string s, t;

	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> s >> t;

		count = 0;
		tIndex = 0;
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());

		for (j = 0; j < s.length(); j++) {
			if (s[j] == t[tIndex] && count % 2 == 0) {
				count = 0;
				tIndex++;
			}
			else
				count++;

			if (tIndex >= t.length())
				break;
		}

		if (j == s.length())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}