#include <iostream>
#include <string>

using namespace std;

int N;
string s[20], t[20];

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		s[i] = str;
		cin >> str;
		t[i] = str;
	}
}

void Reduce(string str1, string str2)
{
	int idx = str1.length() - 1;
	int a = 0;
	bool first = false;

	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[idx - i] == str2.back())
		{
			if ((i - a) % 2 == 0 && first == false)
			{
				str2.pop_back();
				a = i;
				first = true;
			}
			if ((i - a) % 2 == 1 && first == true)
			{
				str2.pop_back();
				a = i;
			}
		}
		if (str2.empty())
		{
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

void Solve()
{
	Input();
	for (int i = 0; i < N; i++)
	{
		Reduce(s[i], t[i]);
	}
}

int main()
{
	Solve();
	return 0;
}