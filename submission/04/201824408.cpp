#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "timebomb.h"
#include <queue>
using namespace std;

int main()
{
	int N, result, ans, max;
	queue<int> q;
	queue<pair<int, int>> pair;

	box_ready();
	N = box_size();

	for (int i = 1; i <= N; i+=2)
	{
		int j = i + 1;
		if (i == N)
		{
			j = 1;
		}
		result = box_comp(i, j);
		pair.push(make_pair(i, j));

		if (result == 1)
		{
			q.push(i);
		}
		else
		{
			q.push(j);
		}
	}
	while (q.size() != 1)
	{
		int i = q.front();
		q.pop();
		int j = q.front();
		q.pop();
		result = box_comp(i, j);
		pair.push(make_pair(i, j));

		if (result == 1)
		{
			q.push(i);
		}
		else
		{
			q.push(j);
		}
	}
	max = q.front();
	q.pop();
	int size = pair.size();

	for (int i = 0; i < size; i++)
	{
		int a = pair.front().first;
		int b = pair.front().second;
		pair.pop();
		if (a == max)
		{
			q.push(b);
		}
		else if (b == max)
		{
			q.push(a);
		}
	}
	while (q.size() != 1)
	{
		int i = q.front();
		q.pop();
		int j = q.front();
		q.pop();
		result = box_comp(i, j);
		pair.push(make_pair(i, j));

		if (result == 1)
		{
			q.push(i);
		}
		else
		{
			q.push(j);
		}
	}
	ans = q.front();
	box_report(ans);

	return 0;
}