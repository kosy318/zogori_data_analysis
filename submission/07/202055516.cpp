#include<bits/stdc++.h>

using namespace std;

int N, b, e, c;
tuple<int, int, int> reserve[100];
pair<int,int> dp[360*3+1];
int work, last=0;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> b >> e >> c;
        // e�� �������� �����ϱ� ����
        reserve[i] = {e, b, c};
        if(e > last) last = e;
    }
}

void solve() {
    dp[0] = {0, 0};
    // ����) sort�� �ι�° ���ڴ� ������ ����+1
    sort(&reserve[0], &reserve[N]);
    int j=0;
    for(int i=1; i<last+1; i++) {
        // �ش� ���� �������� �ʰų� ���� ��
        dp[i].first = dp[i-1].first;
        dp[i].second = dp[i-1].second;
        while(j<N && get<0>(reserve[j])==i) {
            // �ش� ���� ���� �������� ��
            // c = �ش� �� + ���� ��
            c = get<2>(reserve[j]) + dp[get<1>(reserve[j])-1].first;
            // work = ���� �� + �ش� ��
            work = dp[get<1>(reserve[j])-1].second + get<0>(reserve[j]) - get<1>(reserve[j]) + 1;
            // c���� �̵���� ���ֱ�
            if(dp[get<1>(reserve[j])-1].second > 1) c -= 10;
            if(dp[i].first == c && dp[i].second > work) {
                dp[i].second = work;
            } else if(dp[i].first < c) {
                dp[i].first = c;
                dp[i].second = work;
            }
            j++;
        }
    }
    cout << dp[last].first << " " << dp[last].second << endl;
}

int main() {
    input();
    solve();
    return 0;
}
