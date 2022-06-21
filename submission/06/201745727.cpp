#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  string in;
  cin >> in;
  vector<vector<string>> set_code(in.length(), (vector<string> (in.length())));

  for(int i=0; i < in.length(); i++){
    set_code[i][i] = in[i];
  }

  int j = 1;
  while(j < in.length()){
    for (int x = 0, y = x + j; y < in.length(); x++, y++){
      if (in[x] == in[y]){
        set_code[x][y] = in[x] + set_code[x+1][y-1] + in[y];
      }
      else{
        if (set_code[x+1][y].size() > set_code[x][y-1].size())
          set_code[x][y] = set_code[x+1][y];
        else if (set_code[x+1][y].size() < set_code[x][y-1].size())
          set_code[x][y] = set_code[x][y-1];
        else{
          if (set_code[x+1][y] >= set_code[x][y-1])
            set_code[x][y] = set_code[x][y-1];
          else
            set_code[x][y] = set_code[x+1][y];
        }

      }
    }
    j++;
  }
  cout << set_code[0][in.length() - 1];
}
