#include <bits/stdc++.h>
using namespace std;

struct schedule {
	int b, e, cost;
};

struct opt {
	int money, cnt, day;
};

int N, E;
vector<schedule> calendar;
vector<opt> M;

bool mycmp(schedule a, schedule b) {
	if (a.e == b.e) {
		if (a.b == b.b) { return a.cost < b.cost; }
		return a.b < b.b;
	}
	return a.e < b.e;
}

void read() {
	int b, e, c;
	schedule work; opt o;
	o.money = 0; o.cnt = 0; o.day = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> b >> e >> c;
		work.b = b; work.e = e; work.cost = c;
		calendar.push_back(work);
	}
	sort(calendar.begin(), calendar.end(), mycmp);

	E = calendar[N - 1].e;
	for (int i = 0; i <= E; i++) { M.push_back(o); }
}

opt best_schedule(opt t1, opt t2) {
	opt result;
	int t1_money, t2_money;
	t1_money = t1.money - (t1.cnt - 1) * 10;
	t2_money = t2.money - (t2.cnt - 1) * 10;
	if (t1_money > t2_money) { result = t1; }
	else if (t1_money < t2_money) { result = t2; }
	else {
		if (t1.day < t2.day) { result = t1; }
		else { result = t2; }
	}
	return result;
}

opt prev_opt(int n) {
	for (int i = n; i >= 0; i--) {
		if (M[i].cnt != 0) { return M[i]; }
	}
	return M[0];
}

void optimizing() {
	opt a, b;

	for (auto w : calendar) {
		a = prev_opt(w.e - 1);
		b = prev_opt(w.b - 1);
		b.money += w.cost; b.cnt += 1; b.day += w.e - w.b + 1;
		a = best_schedule(a, b);
		M[w.e] = best_schedule(M[w.e], a);
	}
}

void outcome() {
	int money = M[E].money - (M[E].cnt - 1) * 10;
	cout << money << " " << M[E].day << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	optimizing();
	outcome();
	return 0;
}
