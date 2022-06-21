#include <iostream>
using namespace std;

int N, wrong, similar;
string word;

int checkPalin(int startIdx, int endIdx) {
    while (startIdx < endIdx) {
        if (word[startIdx] == word[endIdx]) {
            startIdx++;
            endIdx--;
            continue;
        }

        wrong++;
        if (wrong >= 2) break;
        if (word[startIdx+1] == word[endIdx] && word[startIdx] == word[endIdx-1]) {
            if (startIdx == endIdx-1) {
                startIdx++;
                continue;
            }
            int curWrong = wrong;
            checkPalin(startIdx+1, endIdx); //°æ¿ì 1 ·Î ÇØº½
            wrong = curWrong; //restore
            checkPalin(startIdx, endIdx-1);
        } else if (word[startIdx+1] == word[endIdx]) {
            startIdx++;
        } else if (word[startIdx] == word[endIdx-1]) {
            endIdx--;
        } else {
            wrong = -1;
            break;
        }

    }
    if (wrong == 0) return 1;
    else if (wrong == 1) {
        similar++;
        return 2;
    }
    else return 3;
}



int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word;
        similar = 0;
        wrong = 0;
        int result = checkPalin(0, word.length()-1);

        if (result == 1) cout << "1\n";
        else if (similar > 0) cout << "2\n";
        else if (result == 3) cout << "3\n";
        else cout << "2\n";
    }
}
