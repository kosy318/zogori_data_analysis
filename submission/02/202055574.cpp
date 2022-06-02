#include <iostream>
#include <string>
using namespace std;

int check2(string s, string t, int its){
    if(its == 0 && s.size() < t.size()) return 0;
    if(its == t.size() && s.size() % 2 == 0) return 1;
    else if(its == t.size() && s.size() % 2 == 1) return 0;

    string tmp = s;
    int first = 0, result;

    int gap = tmp.find(t[its]);
    while(gap != string::npos){
        tmp.replace(0, gap+1, "");
        if(its == 0 || gap % 2 == first){
            result = check2(tmp, t, its+1);
            if(result == 1) return 1;
        }
        gap = tmp.find(t[its]);
        first = (first == 1 ? 0 : 1);
    }
    return 0;
}

int check1(string s, string t){
    if(s == t) return 1;
    if(s.size() < t.size()) return 0;

    int i=0, result;
    string tmp;
    for(; i<s.size()-1; i++){
        tmp = s;
        tmp.replace(i, 2, "");
        result = check1(tmp, t);
        if(result == 1) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    string s, t;
    int result, gap;

    while(N--){
        cin >> s >> t;
        if(s.size() < 100){
            if((s.size() - t.size())%2 == 1){
                s.replace(0, 1, "");
            }
            result = check1(s, t);
        } else {
            result = check2(s, t, 0);
        }
        if(result == 1) cout << "YES\n";
        else            cout << "NO\n";
    }
}

