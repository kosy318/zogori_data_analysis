#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int is_quasi_palin(string temp) {
    string copy_temp = temp;
    for (int i = 0; i < temp.length(); i++) {
        copy_temp.erase(copy_temp.begin()+i);
        if (copy_temp == string(copy_temp.rbegin(), copy_temp.rend()))
            return 1;
        copy_temp = temp;
    }
    return 0;
}

int main(void){
    string input;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        input.erase(remove(input.begin(), input.end(), ' '), input.end());
        if (input == string(input.rbegin(), input.rend()))
            cout << "1" << endl;
        else if (is_quasi_palin(input))
            cout << "2" << endl;
        else
            cout << "3" << endl;
    }

    return 0;
}
