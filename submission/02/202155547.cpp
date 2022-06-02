#include <iostream>
#include <string>

using namespace std;

int is_yes(string s1, string s2, int start, int len1, int len2)
{
    int s1_index = start;
    int s2_index = 0;

    for (int i=start; i<len1; i++)
    {
        if (s1[i] == s2[s2_index]) 
        {
            if (s2_index == len2-1) // case A: s2 finish
            {
                if (len2 == 1) return 1;                //  case A-1: if the length of s2 is 1, return YES.                    ex) s1="algorithm", s2="m"
                if ((i - s1_index - 1) % 2) continue;   // *case A-2: if the distance between s1_index and i is odd, continue. ex) s1="bab", s2="bb" -> distance is 1(a)
                if ((len1 - i - 1) % 2) continue;       // *case A-3: if the length of remaining string is odd, continue.      ex) s1="bbc", s2="bb" -> remaining length is 1(c)
                return 1;                               //  case A-4: other, return YES
            }
            // *why does A-2, A-3 continue, not return NO? --> it could be YES from the remaining string ex) s1="abbcdefd", s2="ad" (0,4 is no. but 0,10 is yes)
            s2_index ++;         // case A: s2 remain

            if (i==start) continue;            // start of for loop
            else if ((i - s1_index - 1) % 2){  // same with case A-2 (i != start)
                s2_index --;
                continue;
            }
            else s1_index = i;
        }
    }
    return 0;
}
int backspace(string s1, string s2)
{
    int s1_len = s1.length();
    int s2_len = s2.length();

    if (s1_len < s2_len) return 0;

    for(int i=0; i<s1_len; i++)
    {
        if (s1[i] == s2[0])
            if(is_yes(s1, s2, i, s1_len, s2_len)) return 1;
    }
    return 0;
}
int main()
{

    int N;
    string test1, test2;
    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> test1 >> test2;
        if (backspace(test1, test2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
