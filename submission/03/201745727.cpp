#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int reverse_bread(vector<int>& bread){
  int value, index = 0;
  for (int i = 0; i < bread.size(); i++){
    if (bread[i] != i + 1){
      value = i + 1;
      for (int j = i; j < bread.size(); j++) {
        if (abs(bread[j]) == value) { index = j; break; }
      }
      reverse(bread.begin() + i, bread.begin() + index + 1);
      for (int j = i; j < index + 1; j++){ bread[j] = bread[j] * (-1); }
      break;
    }
  }

  for (int i = 0; i < bread.size(); i++){
    if (bread[i] != i + 1)
      return 0;
  }
  return 1;
}

int back_reverse_bread(vector<int>& bread) {
  int value, index = 0;
  int b_index = bread.size() - 1;

  for (int i = b_index; i >= 0; i--){
    if (bread[i] != i + 1){
      value = i + 1;
      for (int j = i; j >= 0; j--){
        if (abs(bread[j]) == value) { index = j; break; }
      }
      reverse(bread.begin() + index, bread.begin() + i + 1);
      for (int j = index; j < i + 1; j++){ bread[j] = bread[j] * (-1); }
      break;
    }
  }

  for (int i = 0; i < bread.size(); i++) {
    if (bread[i] != i + 1)
      return 0;
  }
  return 1;
}

int main() {
  int num;
  cin >> num;
  int i = 0;

  while (i < 5){
    vector<int> bread;
    vector<int> temp_b;
    int b = 0;
    int n = num;

    while(n > 0){
      cin >> b;
      bread.push_back(b);
      temp_b.push_back(b);
      n--;
    }

    if (reverse_bread(bread) == 1){ cout << "one" << endl; }
    else{
      back_reverse_bread(temp_b);   // reverse 과정 사전 시행 -> 1번만에 안되었기 때문에
      if (reverse_bread(bread) == 1 || back_reverse_bread(temp_b) == 1){ cout << "two" << endl; }
      else { cout << "over" << endl; }
    }
    i++;
  }
}
