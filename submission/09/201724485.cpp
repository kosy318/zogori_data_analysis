#include <bits/stdc++.h>
using namespace std;

struct opt {
	long long p, m;
};

vector<long long> num;
vector<char> op;
vector<vector<opt>> M;

void read() {
	string str;
	getline(cin, str);
	vector<char> input(str.begin(), str.end());
	for(int i = 0; i < input.size(); i++) {
		if (input[i] == ' ') { continue; }
		if ('0' <= input[i] && input[i] <= '9') {
			num.push_back((long long)(input[i] - '0'));
		}
		else if (input[i] == '-') {
			if ('0' <= input[i+1] && input[i+1] <= '9') {
				num.push_back((long long)(-1 * (input[i+1] - '0')));
				i++;
			}
			else { op.push_back(input[i]); }
		}
		else { op.push_back(input[i]); }
	}

	opt o; o.p = 0LL; o.m = 0LL;
	vector<opt> v(num.size(), o);
	M = vector<vector<opt>> (num.size(), v);
}

opt operating(opt temp1, opt temp2, int i) {
	opt result;
	vector<long long> v;
	switch(op[i]) {
		case '+': {
			v.push_back((long long)(temp1.p + temp2.p));
			v.push_back((long long)(temp1.p + temp2.m));
			v.push_back((long long)(temp1.m + temp2.p));
			v.push_back((long long)(temp1.m + temp2.m));
			break;
		}
		case '-': {
			v.push_back((long long)(temp1.p - temp2.p));
			v.push_back((long long)(temp1.p - temp2.m));
			v.push_back((long long)(temp1.m - temp2.p));
			v.push_back((long long)(temp1.m - temp2.m));
			break;
		}
		case '*': {
			v.push_back((long long)(temp1.p * temp2.p));
			v.push_back((long long)(temp1.p * temp2.m));
			v.push_back((long long)(temp1.m * temp2.p));
			v.push_back((long long)(temp1.m * temp2.m));
			break;
		}
	}
	result.p = (long long)(*max_element(v.begin(), v.end()));
	result.m = (long long)(*min_element(v.begin(), v.end()));
	return result;
}

opt money(int i, int j) {
	if (M[i][j].p != 0 && M[i][j].m != 0) { return M[i][j]; }
	if (i == j) {
		opt temp; temp.p = (long long)(num[i]); temp.m = (long long)(num[i]);
		return M[i][j] = temp;
	}

	opt temp;
	vector<long long> big, sml;
	for(int k = i; k < j; k++) {
		temp = operating(money(i, k), money(k+1, j), k);
		big.push_back((long long)(temp.p));
		sml.push_back((long long)(temp.m));
	}
	M[i][j].p = (long long)(*max_element(big.begin(), big.end()));
	M[i][j].m = (long long)(*min_element(sml.begin(), sml.end()));
	return M[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	if (num.size() == 0) { cout << 0 << "\n"; }
	else {
		opt t = money(0, num.size()-1);
		cout << t.p << "\n";
	}
	return 0;
}
