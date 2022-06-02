#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void reverse(std::vector<int>& fishesCopy, int left, int right) {
    if (left > right) {
        int temp = left;
        left = right;
        right = temp;
    }
    while (left < right) {
        int temp = -fishesCopy[left];
        fishesCopy[left] = -fishesCopy[right];
        fishesCopy[right] = temp;

        left++;
        right--;
    }

    if (left == right) {
        fishesCopy[left] = -fishesCopy[left];
    }
}

int findIdx(std::vector<int>& fishesCopy, int target, int start, int searchDirection) {
    
    for (int i=start; 1<=i && i<fishesCopy.size(); i+=searchDirection) {
        if (std::abs(fishesCopy[i]) == target) {
            return i;
        }
    }
    return -1;
}

int main() {

    int k;
    std::cin >> k;

    for (int testCase=0; testCase<5; testCase++) {
        std::vector<int> fishes(k+1, 0);

        for (int i=1; i<=k; i++) {
            std::cin >> fishes[i];
        }

        std::vector<int> copy = fishes;
        int frontCount = 0;
        for (int i=1; i<=k && frontCount < 3; i++) {
            if (copy[i] != i) {
                int found = findIdx(copy, i, i, 1);
                reverse(copy, i, found);
                if (copy[i] == -i) {
                    frontCount++;
                }
                frontCount++;
            }
        }

        copy = fishes;
        int backCount = 0;
        for (int i=k; i>=1 && backCount < 3; i--) {
            if (copy[i] != i) {
                int found = findIdx(copy, i, i, -1);
                reverse(copy, found, i);
                if (copy[i] == -i) {
                    backCount++;
                }
                backCount++;
            }
        }

        int count = std::min(frontCount, backCount);

        if (count == 1) {
            std::cout << "one\n";
        }
        else if (count == 2) {
            std::cout << "two\n";
        }
        else if (count >= 3) {
            std::cout << "over\n";
        }
        else {
            std::cout << "error\n";
        }
        
    }
}