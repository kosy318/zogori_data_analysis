#include <bits/stdc++.h>
using namespace std;

typedef enum StrType_ {PALIN = 1, QUASI, NORMAL} StrType; 

bool isPalindromeInRange(const string& str, int begin, int end);
StrType getStringType(const string& str);

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        
        StrType strType = getStringType(str);
        cout << strType << endl;
    }

    return 0;
}

bool isPalindromeInRange(const string& str, int begin, int end) {
    bool result = true;
    int headCursor = begin;
    int tailCursor = end;    

    while (headCursor < tailCursor) {
        if ( str.at(headCursor) != str.at(tailCursor) ) {
            result = false;
            break;
        }

        ++headCursor;
        --tailCursor;
    }

    return result;
}

StrType getStringType(const string& str) {
    StrType strType = PALIN;

    int headCursor = 0;
    int tailCursor = str.length() - 1;

    while (headCursor < tailCursor) {
        if ( str.at(headCursor) != str.at(tailCursor) ) { // pair 불일치 발생 => 일단 회문은 아님
            if ( isPalindromeInRange(str, headCursor, tailCursor - 1) ) { // 뒤쪽 문자 제거시 회문이 되는경우 => 유사회문
                strType = QUASI;
                break;
            }
            else if ( isPalindromeInRange(str, headCursor + 1, tailCursor) ) { // 앞쪽 문자 제거시 회문이 되는경우 => 유사회문
                strType = QUASI;
                break;
            }
            else { // 어떻게 문자를 제거해도 회문이 되지않는 경우 => 평문
                strType = NORMAL;
                break;
            }
        }
        
        ++headCursor;
        --tailCursor;
    }

    return strType;
}