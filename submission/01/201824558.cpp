#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	int res, start, end, starttmp, endtmp;
	int flag;
	string s;

	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		res = 1;
		flag = 0;
		cin >> s;
		start = 0;
		end = s.length()-1;
		while (start < end) 
		{
			if (s[start] != s[end] && flag == 0) {
				res = 2;
				starttmp = start;
				endtmp = end;
				start += 1;
				flag = 1;
			}
			else if (s[start] != s[end] && flag == 1) {
				start = starttmp;
				end = endtmp - 1;
				flag = 2;
			}
			else if (s[start] != s[end] && flag == 2) {
				res = 3;
				break;
			}
			else {
				start++;
				end--;
			}
		}
		cout << res << endl;
	}
}