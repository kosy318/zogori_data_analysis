#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s, t;
string::iterator pointS, pointT;
stack<string::iterator> pointStack;

void solve() {
    if(s.length() < t.length()) {
        cout << "NO\n";
        return;
    }

    pointS = s.end() - 1;
    pointT = t.end() - 1;

    while(pointT >= t.begin()) {
        while(pointS >= s.begin()) {
            if(*pointS == *pointT) {
                pointStack.push(pointS);
                pointS -= 1;
                pointT -= 1;
            }
            else {
                pointS -= 2;
            }

            if(pointT < t.begin()) {
                cout<< "YES\n";
                return;
            }
        }
        if(pointT == t.end() - 1) {
            cout << "NO\n";
            return;
        }
        pointS = pointStack.top();
        pointS -= 2;
        pointStack.pop();
        pointT++;
    }
}

void input() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) { 
        cin >> s >> t;
        solve();
    }
}

int main()
{
    input();
    return 0;
}
