#include <iostream>
#include <vector>
#include "timebomb.h"
using namespace std;

vector<int> larger;
vector<pair<int, int>> vs;

void find_max(){
  while (larger.size() != 1){
    vector<int> tmp;

    for(int i=0; i < larger.size(); i++){
      if (i == larger.size() - 1){
        tmp.push_back(larger[i]);
        break;
      }
      vs.push_back(make_pair(larger[i], larger[i+1]));
      if (box_comp(larger[i], larger[i+1]) == -1)
        tmp.push_back(larger[i+1]);
      else
        tmp.push_back(larger[i]);
      i++;
    }
    larger.clear();
    larger = tmp;
  }
}

void make_vs(int idx){
  for (int i = 0; i < vs.size(); i++){
    if (vs[i].first == idx)
      larger.push_back(vs[i].second);
    else if (vs[i].second == idx)
      larger.push_back(vs[i].first);
  }
}

int main(){
  int N = 0, This = 0, Max = 0;

  box_ready();
  N = box_size();

  for (int i = 1; i < N+1; i++){
    if (i == N){
      larger.push_back(i);
      break;
    }
    vs.push_back(make_pair(i, i+1));
    if (box_comp(i, i+1) == -1)
      larger.push_back(i+1);
    else
      larger.push_back(i);
    i++;
  }
  find_max();
  Max = larger[0];
  larger.clear();

  make_vs(Max);
  find_max();
  This = larger[0];
  box_report(This) ;
}