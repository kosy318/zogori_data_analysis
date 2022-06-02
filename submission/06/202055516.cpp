#include <bits/stdc++.h>

using namespace std;

string palin[1001][1001];
string text, result, answer;
int len;

string fast(string s1, string s2) {
    for(int i=0; i<s1.length(); i++) {
        if(s1[i] > s2[i]) return s2;
        else if(s1[i] < s2[i]) return s1;
    }
    return s1;
}

void findPalin(int m, int n) {
    for(int i=n; i<m; i++) {
        if(text[i] == text[m]) {
            result = text[i] + palin[m-1][i+1] + text[m];
            return;
        }
    }
    result = text[m];
}

void solve() {
    len = text.length();
    for(int k=0; k<len; k++) {
        palin[k][k] = text[k];
    }

    int add = 1;
    for(int i=1; i<=len; i++) {
        for(int j=i; j<len; j++) {
            result = "";
            // j-add이 포함되는 경우 가장 긴 팰린드롬을 result에 담기
            findPalin(j, j-add);
            // 더 긴 회문이 답, 같으면 순서가 빠른 회문이 답
            if(result.length() > palin[j-1][j-add].length()) {
                palin[j][j-add] = result;
            } else if(result.length() < palin[j-1][j-add].length()) {
                palin[j][j-add] = palin[j-1][j-add];
            } else {
                palin[j][j-add] = fast(result, palin[j-1][j-add]);
            }
        }
        add++;
    }
}

int main() {
    cin >> text;
    solve();
    cout << palin[len-1][0] << endl;
    //output();
}
