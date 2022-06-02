#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void inputData();
int testStr(string oriStr, string revStr);
int findDiff(string oriStr, string revStr);


int main(){
    inputData();
}

void inputData(){
    int n;
    string originStr, reverseStr;
    cin >> n;
    while(n-- > 0){
        cin >> originStr;
        reverseStr = originStr;
        reverse(reverseStr.begin(), reverseStr.end());

        cout << testStr(originStr, reverseStr) << endl;
    }
}

int testStr(string oriStr1, string revStr1){
    if (oriStr1 == revStr1) return 1;

    int index = findDiff(oriStr1, revStr1);
    int size = oriStr1.size();

    string oriStr2 = oriStr1;
    string revStr2 = revStr1;

    oriStr1.erase(oriStr1.begin() + index);
    revStr1.erase(revStr1.begin() + size - 1 - index);
    oriStr2.erase(oriStr2.begin() + size - 1 - index);
    revStr2.erase(revStr2.begin() + index);

    if (oriStr1 == revStr1 || oriStr2 == revStr2) return 2;
    else return 3;
}

int findDiff(string oriStr, string revStr){
    for (int i = 0; i < oriStr.size(); i++){
        if (oriStr[i] != revStr[i])
            return i;
    }
}
