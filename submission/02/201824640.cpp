#include <iostream>
#include <string>

using namespace std;

int main() {
	string origin;
	string compare;
	int maxs;

	cin >> maxs;
	for (int i = 0; i < maxs; i++) {
		cin >> origin;
		cin >> compare;
		int correct = 0;
		int Oindex = origin.length()-1;
		int Cindex = compare.length()-1;

		while(origin.length() > compare.length()+1) {
			if (correct == compare.length()) {
				origin = compare;
				break;
			}
			if (origin[Oindex] != compare[Cindex]) {
				origin.erase(Oindex, 1);
				Oindex -= 1; 
				origin.erase(Oindex, 1);
				Oindex -= 1;
			}
			else {
				if (Cindex != 0) {
					Cindex -= 1;
				}
				Oindex -= 1;
				correct += 1;
			}
		}
		while (true) {
			if (origin == compare) {
				cout << "YES" << endl;
				break;
			}
			else {
				origin.erase(0, 1);
			}
			if (origin == compare) {
				cout << "YES" << endl;
				break;
			}
			else {
				cout << "NO" << endl;
				break;
			}
		}
	}
}