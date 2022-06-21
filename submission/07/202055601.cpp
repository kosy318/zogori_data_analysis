#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Info {
public:
	int start, end, income;

	bool operator < (const Info& i) const {
		if (start != i.start) { return start < i.start; }
		if (end != i.end) { return end < i.end; }
		return income > i.income;
	}
};

class Result {
public:
	int entire_date, end_date, income;

	Result& operator = (Result& r) {
		entire_date = r.entire_date;
		end_date = r.end_date;
		income = r.income;

		return *this;
	}
};


int main() {

	int N;
	cin >> N;
	set<Info> cset;

	for (int i = 0; i < N; i++) {
		Info c;
		cin >> c.start >> c.end >> c.income;
		cset.insert(c);
	}

	vector<Result> rvec;
	set<Info>::iterator it = cset.begin();

	Result max;	// 최댓값 저장할 객체

	for (int i = 0; i < N; i++) {
		if (i == 0) {	// 첫 번째 Job
			Result temp;
			temp.income = it->income;
			temp.entire_date = it->end - it->start + 1;
			temp.end_date = it->end;

			rvec.push_back(temp); max = temp;
			continue;
		}

		// 2번째 Job부터

		it++;
		int t_income = 0, t_day = 0;

		for (int j = i - 1; j >= 0; j--) {	// 이전 Job들, 가능한 게 있으면 우선순위대로
			if (rvec[j].end_date < it->start) {

				if (t_income == 0) { t_income = rvec[j].income; t_day = rvec[j].entire_date; continue; }

				if (rvec[j].income > t_income ||
					rvec[j].income == t_income && rvec[j].entire_date < t_day) {

					t_income = rvec[j].income; t_day = rvec[j].entire_date;
				}
			}
		}


		// 앞선 결과 반영
		Result temp;
		if (t_income != 0) t_income -= 10;	// 이전 Job 선택했다면 수입 -10

		temp.income = it->income + t_income;
		temp.entire_date = (it->end - it->start + 1) + t_day;
		temp.end_date = it->end;

		rvec.push_back(temp);
		if (max.income < temp.income ||
			max.income == temp.income && max.entire_date > temp.entire_date) { max = temp; }
	}

	cout << max.income << " " << max.entire_date;

	return 0;
}