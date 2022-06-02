#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string str[10];
string r_str[10];

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		str[i] = s;
		r_str[i] = s;
		reverse(r_str[i].begin(), r_str[i].end());
	}
}

int Palin(string str, string r_str)
{
	string c_str = str;
	string c_r_str = r_str;
	if (str == r_str)
		return 1;
	int length = str.length();

	for (int i = 0; i < length; i++)
	{
		if (str[i] != r_str[i])
		{
			string substr = str.erase(i, 1);
			string r_substr = r_str.erase(length - i - 1 ,1);
			if (substr == r_substr)
				return 2;
			else
			{
				substr = c_str.erase(length - i - 1, 1);
				r_substr = c_r_str.erase(i, 1);
				if (substr == r_substr)
					return 2;
				else
					return 3;
			}
		}
	}
}

void Solve()
{
	Input();
	for (int i = 0; i < N; i++)
	{
		cout << Palin(str[i], r_str[i]) << endl;
	}
}

int main()
{
	Solve();

	return 0;
}