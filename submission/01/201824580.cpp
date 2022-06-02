#include <bits/stdc++.h>
using namespace std;

int N;
string str;
vector<string> strings;

void input_data() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        strings.push_back(str);
    }
}

bool is_palin(const string& str) {
    int len = str.size();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

bool is_quasi_palin(const string& str) {
    int remove_cnt = 0;
    int front = 0;
    int back = str.size() - 1;

    while (front <= back) {
        if (str[front] != str[back]) {
            if (remove_cnt >= 1) return false;

            if (str[front + 1] == str[back]) {
                front++;
                remove_cnt++;
                continue;
            } else if (str[front] == str[back - 1]) {
                back--;
                remove_cnt++;
                continue;
            } else
                return false;
        }
        front++;
        back--;
    }
    return true;
}

void get_result() {
    for (int i = 0; i < N; i++) {
        if (is_palin(strings[i]))
            cout << "1\n";
        else if (is_quasi_palin(strings[i]))
            cout << "2\n";
        else
            cout << "3\n";
    }
}

void solution() {
    input_data();
    get_result();
}

int main() {
    solution();
    return 0;
}