#include <iostream>
#include <string>
#include <cstdint>

enum
{
    PALINDROME = 1,
    QUASI_PALINDROME,
    ELSE
};

bool isPalindrome(std::string & s)
{
	for(size_t i=0; i<s.length()/2; i++)
	{
		if(s[i] != s[s.length()-i-1])
		{
			return false;
		}
	}
	return true;
}

bool isQuasiPalindrome(std::string & s)
{
	for(size_t i=0;i<s.length();i++)
	{
		std::string buf = s;
		buf.erase(i, 1);
		if(isPalindrome(buf)) return true;
	}
	
	return false;
}
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	size_t N;
	std::cin >> N;

	for(size_t i=0; i<N; i++)
	{
		std::string s;
		std::cin >> s;
		
		if(isPalindrome(s)) std::cout << PALINDROME << '\n';
		else if(isQuasiPalindrome(s)) std::cout << QUASI_PALINDROME << '\n';
		else std::cout << ELSE << '\n';
	}
}
