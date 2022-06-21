#include<bits/stdc++.h>

using namespace std;

long long operand[30];
int operation[30];
pair<long long, long long> money[30][30];
long long num, result, minM, maxM;
int op, inputN, gap;
string opIn;

void input() {
    inputN=0;
    cin >> num;
    operand[inputN] = num;
    while(cin >> opIn) {
        if(opIn=="*") operation[inputN] = 0;
        else if(opIn=="+") operation[inputN] = 1;
        else operation[inputN] = 2; // '-'
        inputN++;
        cin >> num;
        operand[inputN] = num;
    }
}

long long cal(int k, long long m, long long n) { // operation�� k�� ��, m�� n�� ���
    if(k==0) return m*n;
    else if(k==1) return m+n;
    else return m-n;
}

void solve() {
    // �ʱ� ����
    for(int i=0; i<inputN; i++) {
        money[i][i] = {operand[i], operand[i]};
        result = cal(operation[i], operand[i], operand[i+1]);
        money[i][i+1] = {result, result};
    }
    money[inputN][inputN] = {operand[inputN], operand[inputN]};

    // ���

    gap=2;
    while(gap<=inputN) {
        for(int i=0; i+gap<=inputN; i++) {
            //cout << i << " " << i+gap << endl;
            minM = cal(operation[i], money[i][i].first, money[i+1][i+gap].first);
            maxM = minM;
            result = cal(operation[i], money[i][i].second, money[i+1][i+gap].second);
            if(result < minM) minM = result;
            if(result > maxM) maxM = result;

            for(int j=i+1; j<i+gap; j++) {
                // 1. ���� ���� ������
                result = cal(operation[j], money[i][j].first, money[j+1][i+gap].first);
                if(result < minM) minM = result;
                if(result > maxM) maxM = result;
                // 2. ���� ū ������
                result = cal(operation[j], money[i][j].second, money[j+1][i+gap].second);
                if(result < minM) minM = result;
                if(result > maxM) maxM = result;
            }
            //�ּҰ� �ִ� ��� ����
            money[i][i+gap] = {minM, maxM};
        }
        gap++;
    }
}

int main() {
    input();
    solve();
    cout << money[0][inputN].second << endl;
    return 0;
}
