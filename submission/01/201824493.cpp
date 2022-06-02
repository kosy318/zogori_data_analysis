#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ckquasipal(string p, int l, int r, int cnt);

int ckpal(string p,int l, int r, int delcnt) {
	while (l <= r) {
		if (p[l] != p[r]) {
			if (delcnt==0) {
				if (ckquasipal(p, l, r, 1)) return 2;
				else return 3;
			}
			else return 3;
		}
		l++; 
		r--;
	}
	return 1;
}

bool ckquasipal(string p, int l, int r, int delcnt) {
	int middlere1 = 0, middlere2 = 0;
	middlere1 = ckpal(p, l + 1, r,delcnt);
	middlere2 = ckpal(p, l, r - 1,delcnt);
	if (middlere1 == 1 || middlere2 == 1) {
		return true;
	}
	else return false;
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, l, r, result, leng, cnt;
	vector<int> res;
	string p;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		l = 0, r = p.length()-1, cnt = 0;
		result = ckpal(p, l, r,cnt);
		res.push_back(result);
	}
	leng = res.size();
	for (int i = 0; i < leng; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}