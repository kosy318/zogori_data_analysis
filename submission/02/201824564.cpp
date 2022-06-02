#include <iostream>
#include <cstring>

using namespace std;

int isBackspace(int idx, string str, string trg)
{
	if (trg == str)
	{
		return 1;
	}
	
	if (trg == "" && (str.size()%2 == 0))
	{
		return 1;
	}
	
	char c = trg[0];
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == c)
		{
			if (idx == -1 || (i%2 == 0))
			{
				string str_next = str;
				str_next.erase(0, i+1);
				
				string trg_next = trg;
				trg_next.erase(0, 1);
				
				if (isBackspace(i, str_next, trg_next) == 1)
				{
					return 1;
				}
			}
		}
	}
	
	return 0;
}

int main(void)
{
	int N; 
	cin >> N;
 	
 	for (int i = 0; i < N; i++)
 	{
 		string str, trg;
		cin >> str >> trg;
		
		if (isBackspace(-1, str, trg) == true)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
 	
	return 0;
}

