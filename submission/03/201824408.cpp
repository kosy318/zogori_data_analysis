#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, cnt = 1;
vector <int> frame[5];

void Input()
{
	cin >> k;

	for (int i = 0; i < 5; i++)
	{
		frame[i].push_back(0);

		for (int j = 0; j < k; j++)
		{
			int a;
			cin >> a;

			frame[i].push_back(a);
		}
	}
}

bool Determine(vector<int> frame)
{
	for (int i = 0; i < frame.size(); i++)
	{
		if (i != frame[i])
		{
			return false;
		}
	}
	return true;
}

void R_Search(vector<int> frame)
{
	vector <int> f = frame;
	cnt = 1;
	int n1 = 0;
	while (cnt < 3)
	{
		for (int i = f.size() - 1; i > 0; i--)
		{
			if (i != f[i])
			{
				n1 = i;
				break;
			}
		}

		for (int i = f.size() - 1; i > 0; i--)
		{
			if ((f[i] == n1) || (f[i] == -n1))
			{
				reverse(f.begin() + i, f.begin() + n1 + 1);
				for (int j = i; j <= n1; j++)
				{
					f[j] = -f[j];
				}
				break;
			}
		}
		if (!Determine(f))
		{
			cnt++;
		}
		else
		{
			return;
		}
	}
}

void Search(vector<int> frame)
{
	vector<int> f = frame;
	cnt = 1;
	int n1 = 0;
	while (cnt < 3)
	{
		for (int i = 1; i < f.size(); i++)
		{
			if (i != f[i])
			{
				n1 = i;
				break;
			}
		}

		for (int i = 1; i < f.size(); i++)
		{
			if ((f[i] == n1) || (f[i] == -n1))
			{
				reverse(f.begin()+n1, f.begin()+i+1);
				for (int j = n1; j <= i; j++)
				{
					f[j] = -f[j];
				}
				break;
			}
		}
		if (!Determine(f))
		{
			cnt++;
		}
		else
		{
			return;
		}
	}
	R_Search(frame);
}

void Ans()
{
	switch (cnt)
	{
		case 1: cout << "one" << endl; break;
		case 2: cout << "two" << endl; break;
		default: cout << "over" << endl;
		break;
	}
}

void Solve()
{
	Input();
	for (int i = 0; i < 5; i++)
	{
		Search(frame[i]);
		Ans();
	}
}

int main()
{
	Solve();
	return 0;
}