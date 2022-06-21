#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxS = 1010;

string code;
int code_size;

int dp[maxS][maxS];
bool same[maxS][maxS];
bool visited[maxS][maxS];

int lps_len;


void Input() {
    fastio;
    cin >> code; code_size = code.size();
    code = "0" + code;
    memset(dp, 0, sizeof(dp));
    memset(same, false, sizeof(same));
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= code_size; i++) 
        dp[i][i] = 1;
}

int setDP() {
    for (int i = 1; i <= code_size-1; i++) {
        for (int j = 1; j <= code_size-i; j++) {
            int k = i+j;
            if (code[j] == code[k]) {
                dp[j][k] = dp[j+1][k-1] + 2;
                same[j][k] = true;
            } 
            else {
                dp[j][k] = max(dp[j+1][k], dp[j][k-1]);
            }
        }
    }
    return dp[1][code_size];
}

pair<int, int> Dictionary_BFS(int num, int y, int x) {
    int cmp = 127;

    pair<int, int> Result;

    queue < pair<int, int> > Q;

    int dY[2] = {0, 1};
    int dX[2] = {-1, 0};

    visited[y][x] = true;
    Q.push({y, x});

    if (same[y][x]) {
        Result = {y, x};
        return Result;
    }

    if (num == 1) {
        Result = {y, x};
    }

    while (!Q.empty()) {
        int yy = Q.front().first;
        int xx = Q.front().second;

        Q.pop();

        for (int i = 0; i < 2; i++) {
            int ny = yy + dY[i];
            int nx = xx + dX[i];

            if (dp[ny][nx] == num && !visited[ny][nx]) {
                if (num == 1) {
                    if (code[ny] < cmp) {
                        cmp = code[ny];
                        Result = {ny, nx};
                    }
                }
                else if (same[ny][nx] && (code[ny] < cmp)) {
                    cmp = code[ny];
                    Result = {ny, nx};
                }
                visited[ny][nx] = true;
                Q.push({ny, nx});
            }
        }
    }
    return Result;
}

string getLPS() {
    string Answer = "";
    int y = 1, x = code_size;

    stack <char> s;
    for (int i = lps_len; i > 0; i -= 2) {
        auto P = Dictionary_BFS(i, y, x);

        s.push(code[P.first]);
        if (i != 1) Answer += code[P.first];
        y = P.first+1; x = P.second-1;
    }
    while (!s.empty()) {
        Answer += s.top();
        s.pop();
    }
    return Answer;
}

void Solution() {
    lps_len = setDP();
    cout << getLPS();
}

void p(){
    for (int i = 1; i <= code_size; i++) {
        for (int j = 1; j <= code_size; j++) {
            cout << same[i][j] << " ";
        }
        cout << "\n";
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    Solve();
}