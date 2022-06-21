#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class PD {
public:
    int P;
    int D;

    PD() : P(0), D(0) {};
    PD(int p, int d) : P(p), D(d) {};

    bool operator < (const PD& pd) const {
        if (P != pd.P) return P < pd.P;
        return D > pd.D;
    }
};

multimap<pair<int, int>, int> calendar;

int main()
{
    int N;
    cin >> N;

    int b, e, c, max_e = 0;
    for (int i = 0; i < N; i++) {
        cin >> b >> e >> c;
        calendar.insert({{e, b}, c});

        if (max_e < e) max_e = e;
    }

    PD day[max_e + 1];
    int it_b, it_e, P, D, temp_e = 0;

    for (auto it = calendar.begin(); it != calendar.end(); it++) {
        int it_b = it->first.second;
        int it_e = it->first.first;
        int P = it->second;
        int D = it_e - it_b + 1;

        for (int i = temp_e + 1; i < it_e; i++)
            day[i] = day[i - 1];

        if (day[it_b - 1].P != 0) {
            P += day[it_b - 1].P - 10;
            D += day[it_b - 1].D;
        }

        PD temp_PD(P, D);
        day[it_e] = max({temp_PD, day[it_e - 1], day[it_e]});

        temp_e = it_e;
    }

    cout << day[max_e].P << " " << day[max_e].D;
}
