#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long table[30][30] = { 0 };
long long worst[30][30] = { 0 };
vector<int> num;
vector<char> op;

void Input()
{
	string str;
	getline(cin,str);

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			continue;
		}
		else if(str[i] == '+' || str[i] == '*' || str[i] == '-')
		{
			if (i < str.length()-1 && str[i + 1] != ' ')
			{
				num.push_back(stoi(str.substr(i, 2)));
			}
			else
			{
				op.push_back(str[i]);
			}
		}
		else
		{
			if (i > 0 &&str[i - 1] == '-')
			{
				continue;
			}
			else
			{
				num.push_back(str[i] - '0');
			}
		}
	}

	for (int i = 0; i < num.size(); i++)
	{
		table[i][i] = num[i];
		worst[i][i] = num[i];
	}

}

long long calculate(long long a, long long b,int n)
{
	switch (op[n])
	{
		case '+': return a + b;
			break;
		case '-': return a - b;
			break;
		case '*': return a * b;
			break;
		default:
		break;
	}
}

void DP()
{
	int l = num.size() - 1;

	for (int k = 1; k < num.size(); k++)
	{
		for (int i = 0; i < l; i++)
		{
			int j = i + k;
			int cnt = j - i;
			long long maxe = -9999999;
			long long mine = 99999999;
			for (int m = 0; m < cnt; m++)
			{
				if (maxe < max({ calculate(table[i][i + m], table[i + m + 1][j], i + m), calculate(table[i][i + m], worst[i + m + 1][j], i + m),
					calculate(worst[i][i + m], table[i + m + 1][j], i + m), calculate(worst[i][i + m], worst[i + m + 1][j], i + m) }))
				{
					maxe = max({ calculate(table[i][i + m], table[i + m + 1][j], i + m), calculate(table[i][i + m], worst[i + m + 1][j], i + m),
						calculate(worst[i][i + m], table[i + m + 1][j], i + m), calculate(worst[i][i + m], worst[i + m + 1][j], i + m) });
				}
				if (mine > min({ calculate(table[i][i + m], table[i + m + 1][j], i + m), calculate(table[i][i + m], worst[i + m + 1][j], i + m),
					calculate(worst[i][i + m], table[i + m + 1][j], i + m), calculate(worst[i][i + m], worst[i + m + 1][j], i + m) }))
				{
					mine = min({ calculate(table[i][i + m], table[i + m + 1][j], i + m), calculate(table[i][i + m], worst[i + m + 1][j], i + m),
						calculate(worst[i][i + m], table[i + m + 1][j], i + m), calculate(worst[i][i + m], worst[i + m + 1][j], i + m) });
				}
			}
			table[i][j] = maxe;
			worst[i][j] = mine;
		}
		l--;
	}
}
void Solve()
{
	Input();
	DP();
	cout << table[0][num.size() - 1];
}

int main()
{
	Solve();

	return 0;
}