#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
vector<int> Exist;
string S;
string T;


void Find_next(string s,string t,int start,int cnt){
    int cur = start;
    while(true){
        if(cnt == t.length()){
            if(cur == s.length() -1 || (s.substr(cur+1)).length() % 2 == 0){  //
                Exist.push_back(1);
                return;
            }
            else return;
        }
        int next = s.find_first_of(t[cnt],cur);
        if(next == string::npos) return;
        if((next - start) % 2 == 1){
            Find_next(s,t,next,cnt+1);
            cur = next + 1;
        }
        else cur = next + 1;
    }
}

void Find_first(string s,string t){
    if (S.length() < T.length() || S.find_first_of(T[0]) == string::npos) return;

    int cur = 0;
    while(true){
        int start = s.find_first_of(t[0],cur);
        if(start == string::npos) return;
        if(t.length() == 1){        // 길이가 1인경우 무조건 가능
            Exist.push_back(1);
            return;
        }
        Find_next(s,t,start,1);
        if(!Exist.empty()) return; // 찾으면 탈출
        cur = start + 1;
    }
}

void Backspace(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> S;
        cin >> T;

        Find_first(S, T);

        if (!Exist.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;

        Exist.clear();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Backspace();
    return 0;
}