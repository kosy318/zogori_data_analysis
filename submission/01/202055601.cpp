#include <iostream>
#include <string>

using namespace std;

int check(string& str, int num) {
	if (num >= 2) return 3;
	
	int len = str.length();
	
	for (int i = 0; i < len/2; i++) {
		if (str[i] != str[len-1-i]) {
			string str1 = str;
			string str2 = str;
			
			str1.erase(str1.begin() + i);
			str2.erase(str2.begin() + len-1-i);
			
			if ((check(str1, num+1) != 1 && check(str2, num+1) != 1)) return 3;
			else return 2;
			
			break;
		}
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	
	string strList[n];
	for (int i=0; i<n; i++) { cin >> strList[i]; }	
	for (int i=0; i<n; i++) { cout << check(strList[i], 0) << endl; }
	
	return 0;
}
