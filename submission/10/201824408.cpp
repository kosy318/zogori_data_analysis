#include <iostream>
#include <algorithm>

using namespace std;

struct work
{
	int c;
	int d;
	bool chk = false;
};
int N, T, k;
work W[100];
int M[5][11] = { 0 };
int cnt = 0;

bool cmp(work a, work b)
{
	return a.c > b.c;
}

void Input()
{
	cin >> N >> T >> k;

	for (int i = 0; i < N; i++)
	{
		cin >> W[i].c >> W[i].d;
	}
	sort(W, W + N, cmp);
}

void Greed()
{
	bool a = true;

	while (cnt < k*T)
	{
		for (int i = 0; i < N; i++)
		{
			int day = W[i].d;
			while (W[i].chk != true)
			{
				for (int j = 0; j < k; j++)
				{
					if (M[j][day] == 0)
					{
						M[j][day] = W[i].c;
						W[i].chk = true;
						cnt++;
						break;
					}
					if (j == k - 1)
					{
						day--;
					}
				}
				if (day == 0)
					break;
			}
			if (i == N - 1)
			{
				a = false;
				break;
			}
		}
		if (!a)
			break;
	}
}

void Cost()
{
	int cost = 0;
	int minc = 100000;
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			cost += M[i][j];
			if (M[i][j] < minc && M[i][j]!= 0)
			{
				minc = M[i][j];
			}
		}
	}
	cout << cost << " ";
	int pre = 100000;
	int min = 100000;

	for (int i = 0; i < N; i++)
	{
		if (W[i].chk == false)
		{
			int day = W[i].d;
			for (int l = 0; l < k; l++)
			{
				for (int j = day; j >= 1; j--)
				{
					if (M[l][j] - W[i].c < min)
					{
						pre = min;
						min = M[l][j] - W[i].c;
					}
				}
			}
		}
		if (min == 0)
		{
			min = pre;
		}
	}

	if (cost - min < cost - minc)
		cout << cost - minc << endl;
	else
		cout << cost - min << endl;

}

void Solve()
{
	Input();
	Greed();
	Cost();
}

int main()
{
	Solve();

	return 0;
}