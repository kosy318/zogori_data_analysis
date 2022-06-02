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
        // e를 기준으로 정렬하기 위함
        reserve[i] = {e, b, c};
        if(e > last) last = e;
    }
}

void solve() {
    dp[0] = {0, 0};
    // 주의) sort의 두번째 인자는 끝나는 지점+1
    sort(&reserve[0], &reserve[N]);
    int j=0;
    for(int i=1; i<last+1; i++) {
        // 해당 일을 수락하지 않거나 없을 때
        dp[i].first = dp[i-1].first;
        dp[i].second = dp[i-1].second;
        while(j<N && get<0>(reserve[j])==i) {
            // 해당 일을 했을 수락했을 때
            // c = 해당 일 + 이전 일
            c = get<2>(reserve[j]) + dp[get<1>(reserve[j])-1].first;
            // work = 이전 일 + 해당 일
            work = dp[get<1>(reserve[j])-1].second + get<0>(reserve[j]) - get<1>(reserve[j]) + 1;
            // c에서 이동비용 빼주기
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
