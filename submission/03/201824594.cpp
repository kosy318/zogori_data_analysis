#include <iostream>
#include <algorithm>

using namespace std;

int n;
int fish_bread[100001];
int base[100001];

void flip(int s, int e) {
	for (int i = s; i <= (s + e) / 2; ++i) {
		int temp = fish_bread[e + s - i];
		fish_bread[e + s - i] = fish_bread[i] * -1;
		fish_bread[i] = temp * -1;
	}
}

int find(int s, bool type) {	//type으로 앞에서부터 또는 뒤에서 부터를 결정
	if (type == true) {
		for (int i = s; i <= n; ++i) {
			if (base[i] != fish_bread[i])
				return i;
		}
	}
	else {
		for (int i = s; i >= 1; --i) {
			if (base[i] != fish_bread[i])
				return i;
		}
	}
	return 0;
}

int check() {
	int cnt = 0;
	int start = 1;
	int end = n;

	while (cnt <= 2) {
		start = find(start, true);
		end = find(end, false);
		int s = 0;

		if (start != 0) {
			if ((s = find(fish_bread + start, fish_bread + end, -start) - fish_bread) != end) {
				flip(start, s);
			}
			else if ((s = find(fish_bread + start, fish_bread + end, -end) - fish_bread) != end) {
				flip(s, end);
			}
			else {
				s = find(fish_bread + start, fish_bread + end, start) - fish_bread;	// -
				flip(start, s);
			}
		}
		else {
			break;
		}
		++cnt;
	}

	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		base[i] = i;
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> fish_bread[j];
		}

		int cnt = check();

		switch (cnt) {
		case 1:
			cout << "one\n";
			break;
		case 2:
			cout << "two\n";
			break;
		default:
			cout << "over\n";
		}
	}

	return 0;
}