#include <bits/stdc++.h>

using namespace std;

int N, fish;
vector <int> fishes;
vector<int> fliped;


//����������� Ȯ��
bool checkOrdered() {
	for (int i=0; i<N; i++) {
		if (fliped[i] != i+1) return false;
	}
	return true;
}


//m���� n���� ������
void flip(int m, int n) {
    reverse(fliped.begin()+m, fliped.begin()+n+1);

    for (int i=m; i< n+1; i++) {
        fliped[i] *= -1;
    }
}


// �ѹ� ������ �� ������� ���� �� �ִ���
bool canMake(int k) {
	for (int i=k; i <N; i++) {
		if (fliped[i] != i+1) {
			for (int j = 0; j<N; j++) {
                if (abs(fliped[j])==i+1) {
                    flip(min(j, i), max(j, i));
                    return checkOrdered();
                }
            }
		}
	}
	return false;
}


//�������
void solve() {
	for (int i=0; i<N; i++) {
        fliped.assign( fishes.begin(), fishes.end() );

        if (canMake(i)) { cout << "one" << endl; return; }
        else {
            if (canMake(0)) { cout << "two" << endl; return; }
        }
    }
	cout << "over" << endl;
}


int main() {
	cin >> N;
    for (int i=0; i<5; i++) {
        fishes.clear();
        for (int j=0; j<N; j++) {
            cin >> fish;
            fishes.push_back(fish);
        }
        solve();
    }
    return 0;
}
