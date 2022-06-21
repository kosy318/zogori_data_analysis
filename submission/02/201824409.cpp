#include <iostream>
using namespace std;

bool compute(int start, string s, string t){
    int point = start;
    int cnt = 1;
    while(1){
        if(cnt == t.length()){
            if((s.substr(point)).length() % 2 == 0 or point == s.length() - 1) return true;
            else return false;
        }
        int res = s.find_first_of(t[cnt], point);
        if (res == string::npos) return false;
        else if ((res - start) % 2 != 0){
            point = res + 1;
            start = res;
            cnt++;
        }
        else point = res + 1;
    }
}

bool find(string s, string t){
    if (s.length() < t.length() || s.find(t[0]) == string::npos) return false;
    int point = 0;
    while(1){
        int res = s.find_first_of(t[0], point);
        if(res == string::npos) return false;
        if(t.length() == 1) return true;
        if(compute(res, s, t) == false){
            point = res + 1;
        }
        else return true;
    }
}



int main(){
    int n;
    cin >> n;
    string s, t;
    for(int i = 0; i < n; i++){
        cin >> s;
        cin >> t;
        if(find(s,t) == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
