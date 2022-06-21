#include <iostream>
#include <vector>
using namespace std;

void flip(vector<int>& arr, int i, int j) {
    while(i <= j) {
        int temp = arr[i];
        arr[i] = -arr[j];
        arr[j] = -temp;
        i++; j--;
    }
}

void forwardFlip(vector<int>& arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        if(arr[i] != i+1) {
            for(int j=i; j<n; j++) {
                if(arr[j] == i+1 || arr[j] == -(i+1)) {
                    flip(arr, i, j);
                    return;
        }       
            }
        }
    }
}

void backwardFlip(vector<int>& arr) {
    int n = arr.size();
    for(int i=n-1; i>=0; i--) {
        if(arr[i] != i+1) {
            for(int j=i; j>=0; j--) {
                if(arr[j] == i+1 || arr[j] == -(i+1)) {
                    flip(arr, j, i);
                    return;
        }       
            }
        }
    }
}

bool isOriginal(vector<int>& arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        if(arr[i] != i+1) {
            return false;
        }
    }
    return true;
}

// return 1, 2, or -1(over)
int countFlip(vector<int>& fish) {
    vector<int> fish2 = fish;
    forwardFlip(fish);
    if(isOriginal(fish)) {
        return 1;
    }
    
    backwardFlip(fish2);
    vector<int> fish3 = fish;
    vector<int> fish4 = fish2; 
    forwardFlip(fish);
    backwardFlip(fish3);
    forwardFlip(fish2);
    backwardFlip(fish4);
    if(isOriginal(fish) || isOriginal(fish2) || isOriginal(fish3) || isOriginal(fish4)) {
        return 2;
    } else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k;
    cin >> k;
    for(int i=0; i<5; i++) {
        int t = k;
        vector<int> fish(k);
        while(t--) {
            int n;
            cin >> n;
            fish[k - t - 1] = n;
        }
        
        switch(countFlip(fish)) {
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