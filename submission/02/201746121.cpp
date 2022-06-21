#include <iostream>
#include <deque>
using namespace std;

deque<char> dqT;
int answer;
int firstDeleted = 0;

void operation(deque<char> dqS, int idxS, int idxT) {
        if (answer == 1)
            return;

        if (dqS == dqT) {
            answer = 1;
            return;
        }
        if (idxT >= dqT.size()) {
            if ( (dqS.size() - idxS) % 2 == 0) {
                answer = 1;
                return;
            } else {
                return;
            }
        }
        if (dqS.size() < dqT.size())
            return;

        if (dqS.size() == dqT.size() && dqS != dqT)
            return;


        if (dqS[idxS] == dqT[idxT]) {
            if (firstDeleted == 0) {
                firstDeleted = 1;
                deque<char> dqTemp = dqS;
                dqTemp.pop_front();
                operation(dqTemp, idxS, idxT);
            }
            operation(dqS, idxS+1, idxT+1);

            dqS.erase(dqS.begin()+idxS);
            dqS.erase(dqS.begin()+idxS);
            operation(dqS, idxS, idxT);

        } else {
            if (firstDeleted == 0) {
                firstDeleted = 1;
                deque<char> dqTemp = dqS;
                dqTemp.pop_front();
                operation(dqTemp, idxS, idxT);
            }
            dqS.erase(dqS.begin()+idxS);
            dqS.erase(dqS.begin()+idxS);
            operation(dqS, idxS, idxT);
        }
}
int main() {
    int N;
    cin >> N;
    string s,t;

    for (int i = 0; i < N; i++) {
        cin >> s >> t;
        answer = 0;
        firstDeleted = 0;

        deque<char> dqS(s.begin(), s.end());
        dqT = deque<char>(t.begin(), t.end());
        operation(dqS, 0, 0);
        if (answer == 1) cout << "YES\n";
        else cout << "NO\n";

    }

}
