#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
string code[1000][1000];

void Input()
{
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < str.length(); j++)
		{
			if (i == j)
				code[i][j] = str[i];
			else
				code[i][j] = "";
		}
	}
}

void fillTable()
{
	int l = str.length() - 1;
	for (int k = 1; k < str.length(); k++)
	{
		for (int i = 0; i < l; i++)
		{
			int j = i + k;
			if (str[i] == str[j])
			{
				code[i][j] = str[j] + code[i + 1][j - 1] + str[j];
			}
			else
			{
				if (code[i][j - 1].length() == code[i + 1][j].length())
				{
					if (code[i][j - 1] > code[i + 1][j])
						code[i][j] = code[i + 1][j];
					else
						code[i][j] = code[i][j - 1];
				}
				else if (code[i][j - 1].length() > code[i + 1][j].length())
					code[i][j] = code[i][j - 1];
				else
					code[i][j] = code[i + 1][j];
			}
		}
		l--;
	}
}

void Solve()
{
	Input();
	fillTable();
	cout << code[0][str.length() - 1];
}

int main()
{
	Solve();

	return 0;
}