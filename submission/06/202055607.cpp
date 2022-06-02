#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

int LCS[1024][1024];

int make_table(std::string & forward, std::string & backward, int i, int j)
{
	if(LCS[i][j] != -1)
		return LCS[i][j];

	if (i==forward.length() || j==backward.length())
		return LCS[i][j] = 0;

	if (forward[i] == backward[j])
		return LCS[i][j] = 1 + make_table(forward, backward, i+1, j+1);

	return LCS[i][j] = std::max(make_table(forward, backward, i+1, j), make_table(forward, backward, i, j+1));
}


void secret(std::string & forward, std::string & backward, int idx1, int idx2, int depth)
{

	int answer_len = LCS[0][0];
	static std::string answer;

	if (depth == answer_len)
	{
		std::cout << answer << std::endl;
		exit(0);
	}

	for (char ch : "_abcdefghijklmnopqrstuvwxyz")
	{
		for (int i=idx1; i<forward.length(); i++)
		{
			if (ch==forward[i])
			{
				for (int j=idx2; j<backward.length(); j++)
				{

					if (forward[i]==backward[j] && LCS[i][j] == answer_len-depth)
					{

						bool bCheck = true;

						if( (answer_len / 2) < depth)
						{
							if(backward[j] != answer[answer_len-depth-1])
							{
								bCheck = false;
							}
						}

						if(bCheck)
						{
							answer.push_back(backward[j]);
							secret(forward, backward, i+1, j+1, depth+1);
							answer.pop_back();
						}
						goto L_next;
					}
				}
			}

L_next:
			do {}
			while(0);
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	memset(LCS, -1, sizeof(LCS));

	std::string S;

	std::cin >> S;

	std::string reversed = S;
	std::reverse(reversed.begin(), reversed.end());

	make_table(S, reversed, 0, 0);

	secret(S, reversed, 0, 0, 0);
}
