#include <iostream>
#include <string>

using namespace std;

int N;
string str;

int isPalindrom(string str, int sign)
{
	int p1 = 0;
	int p2 = str.size() - 1;
	
	while (p1 < p2)
	{
		if (str[p1] != str[p2])
		{
			if (sign == 2)
			{
				return 3;
			}
			
			int len = p2 - p1;
			if (isPalindrom(str.substr(p1, len), 2) == 1 || isPalindrom(str.substr(p1+1, len), 2) == 1)
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}
		else
		{
			p1++; p2--;
		}
	}
	
	return 1;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		cout << isPalindrom(str, 1) << endl;
	}
 	return 0;
}

