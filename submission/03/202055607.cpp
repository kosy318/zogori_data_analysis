#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <numeric>

std::vector<std::vector<int32_t>> split(std::vector<int32_t> & data) {
	std::vector<std::vector<int32_t>> result;

	result.push_back(std::vector<int32_t>());
	result[0].push_back(data[0]);

	for(size_t i=1; i<data.size(); i++) {
		if(data[i] != data[i-1]) {
			result.push_back(std::vector<int32_t>());
		}
		result[result.size()-1].push_back(data[i]);
	}

	return result;
}

std::string& fish(std::vector<int32_t> & vDiff) {
	static std::string answer[] = {"one\n", "two\n", "over\n"};
	int32_t sum = std::accumulate(vDiff.begin(), vDiff.end(), 0);
	auto splited = split(vDiff);

	enum {
		ONE = 0,
		TWO,
		OVER
	};

	if(splited[0][0] == 0) {
		splited.erase(splited.begin());
	}

	if(splited[splited.size()-1][0] == 0) {
		splited.pop_back();
	}

	if(splited.size() == 1) {
		return answer[ONE];
	}

	else if(splited.size() == 2) {
		if(sum > 0) {
			return answer[TWO];
		}
	}

	else if(splited.size() == 3) {
		if(splited[0][0] + splited[2][0] == splited[1][0]) {
			return answer[TWO];
		} else if(splited[1][0] == 0) {
			return answer[TWO];
		} else if(splited[0][0] == splited[2][0]) {
			return answer[TWO];
		}
	}

	return answer[OVER];
}
int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	size_t k;
	std::cin >> k;

	for(size_t i=0; i<5; i++) {
		std::vector<int32_t> vDiff;

		for(size_t j=1; j<=k; j++) {
			int32_t cur;
			std::cin >> cur;

			vDiff.push_back(j-cur);
		}

		std::cout << fish(vDiff);
	}
}