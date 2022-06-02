#include <iostream>

using namespace std;

int main()
{
    int N, a, b;
    string s, t;
    bool res;

    cin >> N;
    for(int n=0; n<N; n++)
    {
        cin >> s >> t;

        a = s.length() - 1;
        b = t.length() - 1;
        res = false;

        while(a >= 0)
        {
            if(s[a] == t[b])
            {
                a--;
                b--;
            }
            else
            {
                a -= 2;
            }

            if(b < 0)
            {
                res = true;
                break;
            }
        }

        if(res) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
