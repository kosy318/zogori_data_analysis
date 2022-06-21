#include <iostream>

using namespace std;



bool isPalindrome(string str);
int main()
{
    int N, state, a, b;
    string str;


    cin >> N;
    for(int n=0; n<N; n++)
    {
        cin >> str;

        state = 1;

        a = 0;
        b = str.length() - 1;
        while(a<b)
        {
            if(str[a] != str[b])
            {
                if(isPalindrome(str.substr(a+1, b-a)) || isPalindrome(str.substr(a, b-a)))
                {
                    state = 2;
                    break;
                }
                else
                {
                    state = 3;
                    break;
                }
            }
            a++;
            b--;
        }

        cout << state << endl;
    }

    return 0;
}

bool isPalindrome(string str)
{
    bool res = true;
    for(int i=0; i<str.length()/2; i++)
    {
        if(str[i] != str[str.length()-i-1])
        {
            res = false;
            break;
        }
    }

    return res;
}
