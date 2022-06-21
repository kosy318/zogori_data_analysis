#include <bits/stdc++.h>

using namespace std;

int N, len, differ;
string word;

int quasi(int m, int n) {
    for(int j=0; j<(m+n)/2-m; j++)
        if(word[m+j+1] != word[n-j]) { differ=3; break; }
    if(differ!=3) return 2; // ���� ȸ��

    differ = 2;
    for(int k=0; k<(m+n)/2-m; k++)
        if(word[m+k] != word[n-k-1]) { differ=3; break; }
    if(differ!=3) differ = 2 ; // ���� ȸ��

    return differ;
}

void solve(string word) {
    len = word.length();
    differ = 1;

    for(int i=0; i<len/2; i++) {
        if(differ > 2) break; // �� ��
        else if(word[i] != word[len-1-i]) {
            differ = quasi(i, len-1-i); //����ȸ�� or �� ��
            break;
        }
    }

    switch(differ) {
        case 1 : cout << "1" << endl; break; // ȸ��
        case 2 : cout << "2" << endl; break; // ����ȸ��
        default : cout << "3" << endl; // �� ��
    }
}

int main() {
    cin >> N;
    while(N--) {
        cin >> word;
        solve(word);
    }
    return 0;
}
