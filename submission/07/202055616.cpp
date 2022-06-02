#include<bits/stdc++.h>
using namespace std;

class cmp {
public:
	bool operator()(const tuple<int, int, int>& L, const tuple<int, int, int>& R) const {
		if (get<0>(L) == get<0>(R)) {
			if (get<1>(L) == get<1>(R)) return get<2>(L) < get<2>(R);
			else return get<1>(L) < get<1>(R);
		}
		else return  get<0>(L) < get<0>(R);
	}
};

int N;

set<tuple<int, int, int>, cmp> work;
vector <int> table;
vector <int> day;

void Input() {
	tuple<int, int, int> IN;
	int b, e, c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> b >> e >> c;
		work.insert(make_tuple(b, e, c));
	}
}

void Select(int n, int& P, int& D) {


	auto iter = work.begin();
	advance(iter, n);

	int cnt = 0, index = 0, n_begin = get<0>(*iter);

	for (auto it = work.begin(); it != iter; it++) {
		int test_P = 0, test_D = 365 * 3;
		if (n_begin <= get<1>(*it)) {
			if (index == 0) {
				P = 0;
				D = 365 * 3;
			}
			else if (cnt == 0) {
				P = table[index - 1];
				D = day[index - 1];
			}
			cnt++;
		}
		else {
			if (cnt != 0) {

				Select(index, test_P, test_D);

				if (test_P >= P) {
					P = test_P;
					D = test_D;
				}


			}

		}
		index++;
	}

	if (cnt == 0) {
		P = table[n - 1] + get<2>(*iter) - 10;
		D = day[n - 1] + get<1>(*iter) - get<0>(*iter) + 1;
	}
	else if (cnt == n) {
		P = get<2>(*iter);
		D = get<1>(*iter) - get<0>(*iter) + 1;
	}
	else {
		P += get<2>(*iter) - 10;
		D += get<1>(*iter) - get<0>(*iter) + 1;
	}
	return;
}
void Cleaning() {
	int select, not_select;

	table.push_back(get<2>(*work.begin()));
	day.push_back(get<1>(*work.begin()) - get<0>(*work.begin()) + 1);



	for (int i = 1; i < N; i++) {
		int P = 0, D = 365 * 3;
		not_select = table[i - 1];

		Select(i, P, D);
		select = P;

		if (select > not_select) {
			table.push_back(select);
			day.push_back(D);
		}
		else if (select == not_select) {

			table.push_back(select);

			if (day[i - 1] > D) day.push_back(D);
			else day.push_back(day[i - 1]);
		}
		else {
			table.push_back(not_select);
			day.push_back(day[i - 1]);
		}
	}
}

int main() {
	Input();
	Cleaning();
	cout << table.back() << " " << day.back() << endl;

	return 0;
}
