#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string word;
	while (n--) {
		cin >> word;
		int size = word.size();
		int result = 1;
		for(int i = 0; i < size / 2; i++) {
			if (word[i] != word[size - i - 1]) {
				string word1 = word.substr(i + 1, size - 2 * i - 1);
				string word2 = word.substr(i, size - 2 * i - 1);
				bool flag1 = true, flag2 = true;
				for (int j = 0; j < word1.size() / 2; j++) {
					if (word1[j] != word1[word1.size() - j - 1]) { 
						flag1 = false; break;
					}
				}
				for (int j = 0; j < word2.size() / 2; j++) {
					if (word2[j] != word2[word2.size() - j - 1]) { 
						flag2 = false; break;
					}
				}
				if (flag1 || flag2) result = 2;
				else result = 3;
				break;
			}
		}
		cout << result << '\n';
	}
}