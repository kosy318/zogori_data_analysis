#include <iostream>
#include <string>
using namespace std;

void test_back(string a, string b){
  // b's string longer than a's string => "NO" Case
  if (a.size() < b.size()) {
    cout << "NO" << '\n';
    return ;
  }

  bool is_true = true;
  for(int i=0; i < a.size(); i++){
    int cur = 0, pre, b_index = 0;
    bool first = true;
    for(int j=i; j < a.size(); j++){
      if (a[j] == b[b_index]){
        if (first == true){
          if (b_index == b.size() - 1){ is_true = false; break; }
          cur = j;
          b_index++;
          first = false;
          continue;
        }
        if(first == false) {
          pre = cur;
          cur = j;
          if ((cur - pre - 1) % 2 != 0) { cur = pre; continue; }
        }
        if(b_index == b.size() - 1) {
          if (((a.size() - 1) - cur) % 2 != 0)
            break;
          else { is_true = false; break; }
        }
        b_index++;
      }
    }
    if (is_true == false)
      break;
  }
  if (is_true == false)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  int num;
  string s, t;

  cin >> num;
  while (num > 0){
    cin >> s;
    cin >> t;
    test_back(s, t);
    num--;
  }
}
