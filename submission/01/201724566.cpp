#include <iostream>
#include <string>

using namespace std;

string inpWord;

int solve(int pStart, int pEnd, int ans) {

    while( pStart < pEnd ) {

        if(inpWord[pStart] != inpWord[pEnd]) {
            if(ans == 1) {
                int leftReturn = solve(pStart+1, pEnd, ans+1);
                int rightReturn = solve(pStart, pEnd-1, ans+1);

                if(leftReturn < rightReturn) {
                    ans = leftReturn;
                    pStart++;
                }
                else {
                    ans = rightReturn;
                    pEnd--;
                }
                break;
            }
            else ans = 3;
        }

        if(ans > 2) break;

        pStart++;
        pEnd--;
    }
    return ans;
}

void input() {
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> inpWord;
        cout << solve(0, inpWord.length() - 1, 1) << "\n";
    }
}

int main()
{
    input();
    return 0;
}