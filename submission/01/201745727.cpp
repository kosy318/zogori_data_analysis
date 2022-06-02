#include <iostream>
#include <string>
using namespace std;

void test(string test_str){
  int case1 = 1;
  int case2 = 1;
  string temp = test_str;

  for(int i = 0; i < test_str.size()/2; i++){
    if(test_str[i] != test_str[test_str.size()-i-1]){
      case1 = 0;
      break;
    }
  }
  if (case1 == 1) { cout << "1" << '\n'; }
  else {
    for (int j = 0; j < test_str.size(); j++) {
      case2 = 1;
      test_str.erase(j,1);
      for (int k = 0; k < test_str.size() / 2; k++) {
        if (test_str[k] != test_str[test_str.size() - k - 1]) {
          case2 = 0;
          break;
        }
      }
      test_str = temp;
      if (case2 == 1){
        cout << "2" << '\n';
        return;
      }
    }
    cout << "3" << '\n';
  }
}


int main(){
  int N;
  string test_str;

  cin >> N;
  while(N > 0){
    cin >> test_str;
    test(test_str);
    N--;
  }
}