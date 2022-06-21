#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<string> operators;
pair<long, long> M[31][31];
int size = 0;

void inputData();
void updateMatrix();
long calculate(long n1, long n2, int index);
int myOper(int i);

int main(){
    inputData();
    updateMatrix();

    cout << M[0][nums.size()-1].first << endl;
}

void inputData(){
    int n;
    string oper;
    do{
        cin >> n >> oper;
        nums.push_back(n);
        operators.push_back(oper);
    }while(getc(stdin) == ' '); //ÀÔ·Â ³¡
    operators.pop_back();
}

void updateMatrix(){
    for (int k = 0; k < nums.size(); k++){
        for (int i = 0; i < nums.size() - k; i++){
            int j = k + i;

            if (i == j){
                M[i][j].first = nums[i];
                M[i][j].second = nums[i];
                continue;
            }
            int d = 0;
            vector<long> ns;
            while(true){
                long n1, n2, n3, n4;
                n1 = calculate(M[i][i+d].first, M[i+d+1][j].first, i+d);
                n2 = calculate(M[i][i+d].first, M[i+d+1][j].second, i+d);
                n3 = calculate(M[i][i+d].second, M[i+d+1][j].first, i+d);
                n4 = calculate(M[i][i+d].second, M[i+d+1][j].second, i+d);
                ns.push_back(max({n1, n2, n3, n4}));
                ns.push_back(min({n1, n2, n3, n4}));
                if (i+d+1 == j) break;
                d++;
            }

            M[i][j].first = *max_element(ns.begin(), ns.end());
            M[i][j].second = *min_element(ns.begin(), ns.end());
        }
    }
}

enum {PLUS, MINUS, MUL};

long calculate(long n1, long n2, int i){
    int index = myOper(i);
    switch(index){
        case PLUS: return n1 + n2;
        case MINUS: return n1 - n2;
        case MUL: return n1 * n2;
        default : break;
    }
}

int myOper(int i){
    vector<string> oper{"+", "-", "*"};
    auto it = find(oper.begin(), oper.end(), operators[i]);
    return it - oper.begin();
}
