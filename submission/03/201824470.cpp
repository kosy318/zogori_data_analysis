#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

#define TESTCASE 5

int flip(vector<int> copy_fish_frame) {
    int reverse_count = 0;
    int i = 0;
    while(i < copy_fish_frame.size()) {
        if (i+1 != copy_fish_frame[i]) {
            for (int j = i; j < copy_fish_frame.size(); j++) {
                if (i+1 == abs(copy_fish_frame[j])) {
                    reverse(copy_fish_frame.begin()+i, copy_fish_frame.begin()+j+1);
                    reverse_count++;
                    for (int k = i; k < j+1; k++) {
                        copy_fish_frame[k] = copy_fish_frame[k]*(-1);
                    }
                }
            }
        }
        if (copy_fish_frame[i] > 0) i++;
    }

    return reverse_count;
}

int reverse_flip(vector<int> copy_fish_frame) {
    int reverse_count = 0;
    int i = copy_fish_frame.size()-1;
    while(i > -1) {
        if (i+1 != copy_fish_frame[i]) {
            for (int j = i; j > -1; j--) {
                if (i+1 == abs(copy_fish_frame[j])) {
                    reverse(copy_fish_frame.begin()+j, copy_fish_frame.begin()+i+1);
                    reverse_count++;
                    for (int k = i; k > j-1; k--) {
                        copy_fish_frame[k] = copy_fish_frame[k]*(-1);
                    }
                }
            }
        }
        if (copy_fish_frame[i] > 0) i--;
    }

    return reverse_count;
}


int main(void){
    int K, temp;
    vector<int> fish_frame;

    cin >> K;

    for (int i = 0; i < TESTCASE; i++) {
        for (int j = 0; j < K; j++) {
            cin >> temp;
            fish_frame.push_back(temp);
        }
        int flip_num = flip(fish_frame);
        int flip_num2 = reverse_flip(fish_frame);
        flip_num = flip_num > flip_num2 ? flip_num2 : flip_num;

        if      (flip_num == 1)  cout << "one" << endl;
        else if (flip_num == 2)  cout << "two" << endl;
        else                      cout << "over" << endl;

        fish_frame.clear();
    }

    return 0;
}
