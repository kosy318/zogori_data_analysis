#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <climits>

typedef struct _Request
{
	int32_t b; // begin date
	int32_t e; // end   date
	int32_t c; // cost
} Request;

typedef struct _Response
{
	int32_t P; // Maximum Cost
	int32_t Q; // Minumum Date when P=Max
} Response;

std::vector <Request> g_vRequests;
Response g_Response;
Response g_answer;

int32_t g_start_P = 0;
int32_t g_start_Q = 0;

void dfs(const auto & p, int32_t depth)
{
	for(auto it = p; it != g_vRequests.end(); it++)
	{
		if((*it).b > (*p).e )
		{
			if(depth == 0)
			{
				g_Response.P = g_start_P;
				g_Response.Q = g_start_Q;
			}

			g_Response.P += (*it).c - 10;
			g_Response.Q += (*it).e - (*it).b + 1;

			dfs(it, depth + 1);


			if(g_Response.P > g_answer.P)
			{
				g_answer.P = g_Response.P;
				g_answer.Q = g_Response.Q;
			}
			else if(g_Response.P == g_answer.P)
			{
				if(g_Response.Q < g_answer.Q)
					g_answer.Q = g_Response.Q;
			}


			g_Response.P -= (*it).c - 10;
			g_Response.Q -= (*it).e - (*it).b + 1;

		}
	}
}
int main(void)
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	size_t N;
	std::cin >> N;

	g_answer.P = 0;
	g_answer.Q = INT_MAX;
	
	g_vRequests.resize(N);
	
	for(auto &x : g_vRequests)
	{
		std::cin >> x.b;
		std::cin >> x.e;
		std::cin >> x.c;
	}

	std::sort(g_vRequests.begin(), g_vRequests.end(), [](Request lhs, Request rhs)
	{
		if (lhs.b != rhs.b) return lhs.b < rhs.b;
		else if (lhs.e != rhs.e) return lhs.e < rhs.e;
		return false;
	});


	for(auto it = g_vRequests.begin(); it != g_vRequests.end(); it++)
	{
		if((*it).b <= (*g_vRequests.begin()).e )
		{
			g_start_P = (*it).c;
			g_start_Q = (*it).e -(*it).b + 1;


			if(g_start_P > g_answer.P)
			{
				g_answer.P = g_start_P;
				g_answer.Q = g_start_Q;
			}
			else if(g_start_P == g_answer.P)
			{
				if(g_start_Q < g_answer.Q)
					g_answer.Q = g_start_Q;
			}

			dfs(it, 0);
		}
	}

	std::cout << g_answer.P << " " << g_answer.Q;
}
