#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Subseq{
    int cnt;
    string str;
    bool operator > (Subseq s){
        if (this->str.length() != s.str.length())
            return this->str.length() > s.str.length(); //cnt가 아니고 길이로 비교
        return  this->str <= s.str;
    }
};

void initMatrix(vector<vector<Subseq>>& M, const string& inStr);
void updateMatrix(vector<vector<Subseq>>& M, const string& inStr);

int main(){
    vector<vector<Subseq>> M;
    string inStr;
    cin >> inStr;
    
    initMatrix(M, inStr);
    updateMatrix(M, inStr);

    cout << M[0][inStr.length()-1].str << endl;
}

void initMatrix(vector<vector<Subseq>>& M, const string& inStr){
    //M 초기화
    for (int i = 0; i < inStr.length(); i++){
        vector<Subseq> m;
        for (int j = 0; j < inStr.length(); j++){
            Subseq s;
            s.cnt = 1;
            m.push_back(s);
        }
        M.push_back(m);
    }
}

void updateMatrix(vector<vector<Subseq>>& M, const string& inStr){
    //대각선 순회
    for (int cnt = inStr.length(); cnt >= 0; cnt--){
        for (int i = 0; i < cnt; i++){
            int j = inStr.length() - cnt + i;
            //M 원소 업데이트
            if (i == j){
                M[i][j].str = inStr[i];
                continue;
            }
            if (inStr[i] == inStr[j]){
                M[i][j].cnt = M[i+1][j-1].cnt + 1;
                M[i][j].str = inStr[i] + M[i+1][j-1].str + inStr[i];
            }
            else{
                if (M[i][j-1] > M[i+1][j])  M[i][j] = M[i][j-1];
                else                        M[i][j] = M[i+1][j];
            }
        }
    }
}