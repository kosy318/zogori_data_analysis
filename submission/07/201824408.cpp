#include <iostream>
#include <algorithm>

using namespace std;

struct info
{
	int b;
	int e;
	int c;
	int day;
};

int N;
info work[100];
int table[100] = { 0 };
int D[100] = { 0 };

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> work[i].b;
		cin >> work[i].e;
		cin >> work[i].c;
		work[i].day = work[i].e - work[i].b + 1;
	}
}

bool compare(info a, info b)
{
	if (a.e == b.e)
	{
		return a.b < b.b;
	}
	else
	{
		return a.e < b.e;
	}
}

void Sort()
{
	sort(work, work+N, compare);
}

void DP()
{
	table[0] = work[0].c;
	D[0] = work[0].day;
	int money;
	int day;

	for (int i = 1; i < N; i++)
	{
		money = work[i].c;
		day = work[i].day;
		for (int j = i - 1 ; j >= 0 ; j--)
		{
			if (work[i].b > work[j].e)
			{
				if (table[j] + work[i].c - 10 > money)
				{
					money = table[j] + work[i].c - 10;
					day = D[j] + work[i].day;
				}
				else if (table[j] + work[i].c - 10 == money)
				{
					money = table[j] + work[i].c - 10;
					day = D[j] + work[i].day;
				}
			}
		}
		if (table[i - 1] < money)
		{
			table[i] = money;
			D[i] = day;
		}
		else if (table[i - 1] == money)
		{
			if (D[i - 1] < day)
			{
				table[i] = table[i - 1];
				D[i] = D[i - 1];
			}
			else
			{
				table[i] = money;
				D[i] = day;
			}
		}
		else
		{
			table[i] = table[i - 1];
			D[i] = D[i - 1];
		}
	}
}

void Solve()
{
	Input();
	Sort();
	DP();
	cout << table[N - 1] << " " << D[N - 1] << endl;
}


int main()
{
	Solve();

	return 0;
}