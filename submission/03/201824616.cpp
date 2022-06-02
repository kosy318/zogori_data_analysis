#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> m;
vector<vector<int>> e;
void c_a(int* a, int k) {
    vector<int> mt(2, -1);
    vector<int> et(2, -1);
    int c = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] != i + 1) {
            if (et[0] == -1) et[0] = i;
            et[1] = i;
            c = 0;
            if (i + 1 == k) e.push_back(et);
        }
        else if (et[0] != -1 && (++c > 1 || i + 1 == k)) {
            e.push_back(et);
            et[0] = -1;
        }

        if (a[i] < 0) {
            if (mt[0] == -1) mt[0] = i;
            mt[1] = i;
            if (i + 1 == k || a[i + 1] > 0) m.push_back(mt);
        }
        else mt[0] = -1;
    }
}
bool c_flip(int* a, int s, int e) {
    if (a[s] != -1 - e || a[e] != -1 - s) return 0;
    if (s == e) return 1;
    for (int i = s + 1; i <= e; i++) if (a[i] != a[i - 1] + 1) return 0;
    return 1;
}
void flip(int* a, int s, int e) {
    int temp;
    while (s < e) {
        temp = -a[e];
        a[e--] = -a[s];
        a[s++] = temp;
    }
    if (s == e) a[s] = -a[s];
}
int fish(int* a, int k) {
    m.clear();
    e.clear();
    c_a(a, k);
    if (m.size() == 1 && e.size() == 1) {
        if (m[0] == e[0]) {
            if (c_flip(a, m[0][0], m[0][1])) return 1;
            else {
                int i = 0;
                while (a[m[0][0] + i] != -m[0][0] - 1 && m[0][0] + i != m[0][1]) i++;
                flip (a, m[0][0], m[0][0] + i);
                if (c_flip(a, m[0][0] + i + 1, m[0][1])) return 2;
            }
        }
        else {
            int f = 0, s = 0;
            if (m[0][1] == e[0][1]) { // +-
                while (a[m[0][0] - 1 + f] != -e[0][0] - 1 && m[0][0] - 1 + f != m[0][1]) f++;
                flip(a, e[0][0], m[0][0] - 1 + f);
            }
            else if (m[0][0] == e[0][0]) { // -+
                while (a[m[0][1] + 1 + s] != -e[0][1] - 1 && m[0][1] + 1 + s != m[0][0]) s--;
                flip(a, m[0][1] + 1 + s, e[0][1]);
            }

            if (c_flip(a, e[0][0] + f, e[0][1] + s)) return 2;
        }
    }
    else if (m.size() == 2 && e.size() < 3) {
        if (e.size() == 2 && m[0] == e[0] && m[1] == e[1]) {
            if (c_flip(a, m[0][0], m[0][1]) && c_flip(a, m[1][0], m[1][1])) return 2;
            else {
                flip(a, m[0][0], m[1][1]);
                if (c_flip(a, m[0][1] + 1, m[1][0] - 1)) return 2;
            }
        }
        else if (e.size() == 1) {
            flip(a, m[0][1] + 1, m[1][0] - 1);
            if (c_flip(a, e[0][0], e[0][1])) return 2;
        }
    }
    return 0;
}
int main()
{
    int k;
    cin >> k;
    int a[k];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < k; j++) cin >> a[j];
        int t = fish(a, k);
        if (t == 2) cout << "two\n";
        else if (t == 1) cout << "one\n";
        else cout << "over\n";
    }
}
