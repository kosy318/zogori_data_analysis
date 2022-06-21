#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>

bool backspace(std::string & s, size_t offset1, std::string & t, size_t offset2)
{	
	auto haystack = s.begin() + offset1;
	auto needle = t.begin() + offset2;

	if(needle == t.end())
	{
		if((s.end()-haystack)%2)
			return false;
		return true;
	}
	
	if(haystack == s.end())
		return false;

	while(true)
	{
		auto result = std::search(haystack, s.end(), needle, needle + 1);

		if(result == s.end())
			break;

		if(offset1 ==0 || (result - s.begin() - offset1) % 2 == 0)
		{			
			if(backspace(s, result - s.begin()+1, t, offset2+1))
				return true;
		}

		haystack = result + 1;
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

	std::string answer[2] = {"NO\n", "YES\n"};

	for(size_t i=0; i<N; i++)
	{
		std::string s, t;

		std::cin >> s;
		std::cin >> t;

		std::cout << answer[backspace(s,0,t,0)];
	}
}
