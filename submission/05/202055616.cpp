#include<bits/stdc++.h>
using namespace std;

long MIN;
vector<vector<double> > S(4);
vector<vector<double> > S_n(2);
vector<double> T_n(2,0.5);

long Distance() {

	long d = pow(S_n[0][0] - S_n[1][0], 2) + pow(S_n[0][1] - S_n[1][1], 2) + pow(S_n[0][2] - S_n[1][2], 2);

	return d;
}
void move(int index, double t) {
	
	for (int i = 0; i < 3; i++) {
		S_n[index][i] = S[index * 2][i] * (1 - t) + S[index * 2 + 1][i] * t;
	}

	return;
}


void Station(int index, int pre) {

	int cur=-1;
	double step = 0.00001;
	double temp = T_n[index];
	long left, current, right;
	
	move(index, T_n[index]);
	current = Distance();

	move(index,T_n[index] - step);
	left = Distance();

	move(index, T_n[index] + step);
	right = Distance();

	if (left < current) {
		while (temp >= 0) {
			
			move(index, temp);
			current = Distance();
			
			temp -= step;

			move(index, temp);
			left = Distance();
			
			if (left > current) {
				temp += step;
				cur = 0;
				break;
			}

		}
	}
	else if (right < current) {
		while (temp <= 1) {
			move(index, temp);
			current = Distance();
			temp += step;
			move(index, temp);
			right = Distance();
			if (right > current) {
				temp -= step;
				cur = 0;
				break;
			}
		}
	}
	else {
		temp = temp;
		cur = -1;
	}
	
	if (temp < 0) temp = 0;
	else if (temp > 1) temp = 1;
	
	T_n[index] = temp;
	move(index, T_n[index]);

	if (pre == -1 && cur == -1) return;
	else {
		Station((index + 1) % 2, cur);
		return;
	}
}
void INPUT() {

	int x, y, z;
	for (int i = 0; i < 4; i++) {
		cin >> x >> y >> z;
		S[i].push_back(x);
		S[i].push_back(y);
		S[i].push_back(z);
	}

	for (int j = 0; j < 3; j++) {
		S_n[0].push_back(S[0][j] * (1-T_n[0]) + S[1][j] * T_n[0]);
		S_n[1].push_back(S[2][j] * (1-T_n[1]) + S[3][j] * T_n[1]);
	}
}



int main() {
	INPUT();
	

	Station(0, 0);
	MIN = Distance();


	T_n[0] = 0;
	T_n[1] = 0;
	move(0, T_n[0]);
	move(1, T_n[1]);

	Station(0, 0);
	if(MIN > Distance()) MIN = Distance();


	T_n[0] = 1;
	T_n[1] = 1;
	move(0, T_n[0]);
	move(1, T_n[1]);

	Station(0, 0);
	if (MIN > Distance()) MIN = Distance();

	cout << ceil(sqrt(MIN)) ;
	
	return 0;
}