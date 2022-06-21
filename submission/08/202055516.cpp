#include <bits/stdc++.h>

using namespace std;

string LCQS[101][101];
string S, T;
string answer = "";

void calLongest(int m, int n) {
	for (int i=m; i<m+2; i++) {
		for (int j=n; j<n+2; j++) {
            //길이 초과하면 고려x
            if(i>=S.length() || j>=T.length()) continue;
            //m 또는 n이 0이라서 m-1또는 n-1 계산 못할 때
            else if (m == 0 || n == 0) {
                //한 글자
				if (LCQS[i][j] == "") LCQS[i][j] = S[m];
			}
			// 해당 원소를 포함하지 않았을 때와 반드시 포함했을 때의 길이 비교
			else {
				if (LCQS[i][j].length() < (LCQS[m-1][n-1]+S[m]).length()) {
                    LCQS[i][j] = LCQS[m-1][n-1]+S[m];
				}
				else if (LCQS[i][j].length() == (LCQS[m-1][n-1]+S[m]).length()) {
                    LCQS[i][j] = min(LCQS[i][j], LCQS[m-1][n-1]+S[m]);
				}
			}
			// answer 업데이트
			if(LCQS[i][j].length() > answer.length()) answer = LCQS[i][j];
			else if(LCQS[i][j].length() == answer.length()) answer = min(answer, LCQS[i][j]);
		}
	}
}

int main() {
	cin >> S >> T;

	for (int i=0; i<S.length(); i++) {
		for (int j=0; j<T.length(); j++) {
            //해당 원소를 반드시 포함하는 LCQS
			if (S[i] == T[j]) calLongest(i, j);
		}
	}

	cout << answer << endl;

	return 0;
}
