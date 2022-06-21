#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;

const long long MAX = 30;

// [i, j] 범위 내 연산 최댓값, 최솟값
long long maxCache[MAX][MAX];
long long minCache[MAX][MAX];

void initialize(void)
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			maxCache[i][j] = LLONG_MIN;
			minCache[i][j] = LLONG_MAX;
		}
	}
}

long long calculate(long long a, long long b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

int main(void)
{
	vector <long long> num;
	vector <char> oper;
	int cnt = 0;
	long long temp_num;
	char temp_oper;
	do {
		if (cnt % 2 == 0) {
			cin >> temp_num;
			num.push_back(temp_num);
		}
		else {
			cin >> temp_oper;
			oper.push_back(temp_oper);
		}
		cnt++;
	} while (getc(stdin) == ' ');

	initialize();

	for (int i = 0; i < num.size(); i++)
	{
		maxCache[i][i] = minCache[i][i] = num[i];
	}

	for (int cnt = 1; cnt < num.size(); cnt++)
	{
		for (int idx = 0; idx < num.size() - cnt; idx++)
		{
			for (int i = 1, j = cnt; i <= cnt; i++, j--)
			{
				int opIdx = idx + cnt - j;
				char op = oper[opIdx];

				long long candidates[4] = {
					calculate(maxCache[idx][idx + cnt - j], maxCache[idx + i][idx + cnt], op),
					calculate(maxCache[idx][idx + cnt - j], minCache[idx + i][idx + cnt], op),
					calculate(minCache[idx][idx + cnt - j], maxCache[idx + i][idx + cnt], op),
					calculate(minCache[idx][idx + cnt - j], minCache[idx + i][idx + cnt], op)
				};

				sort(candidates, candidates + 4);

				maxCache[idx][idx + cnt] = max(maxCache[idx][idx + cnt], candidates[3]);
				minCache[idx][idx + cnt] = min(minCache[idx][idx + cnt], candidates[0]);
			}
		}
	}

	long long result = maxCache[0][num.size() - 1];

	cout << result;

	return 0;
}