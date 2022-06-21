#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool ckdis(string t1, int pos, int len1, int rn);

bool ckstring(string t1, string t2, int len1, int num, int pos) {
	while (pos != -1) {
		if ((len1 - pos) % 2 == 1&&pos>=num) {
			break;
		}
		else {
			if (pos == 0 && (len1 - pos) % 2 == 0 ||pos<num) return false;
			pos = t1.rfind(t2[num], pos - 1);
		}
	}
	if (pos == -1) return false;
	else {
		len1 = pos;
		num--;
		if (num < 0) return true;
		pos = t1.rfind(t2[num], pos - 1);
		return ckstring(t1, t2, len1, num, pos);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, pleng;
	string t1, t2, result;
	vector<string> p;
	cin >> n;
	while (n--) {
		cin >> t1; 
		cin >> t2;
		int len1 = t1.length(), len2 = t2.length(), num = len2 - 1;
		int pos = t1.rfind(t2[num]);
		if (len1 < len2) result = "NO";
		else {
			if (ckstring(t1,t2,len1,num,pos)) result = "YES";
			else result = "NO";
		}
		p.push_back(result);
	}
	pleng = p.size();
	for (int i = 0; i < pleng; i++) {
		cout << p[i] << "\n";
	}
	return 0;
}