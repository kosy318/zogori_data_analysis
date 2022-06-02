#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct info{
  int s;
  int e;
  int pay;
  int day;
};

vector<info> clean;

bool compare(info a, info b){
  return a.s < b.s;
}

// Make working space
int make_work(int num){
  int start = 0, end = 0, pay = 0, last = 0;
  while (num > 0){
    info tmp;
    cin >> start >> end >> pay;
    if (last < end)
      last = end;
    tmp.s = start;
    tmp.e = end;
    tmp.pay = pay - 10;
    tmp.day = end - start + 1;
    clean.push_back(tmp);
    num--;
  }
  sort(clean.begin(), clean.end(), compare);
  return last;
}

// Check make the most Profit
int clean_max(int x, int y, int i, vector<int>& dp, vector<int>& day){
  int day_min = 0;
  if (x > y){
    day[clean[i].s] = day[clean[i+1].s];
    return x;
  }
  else{
    if (i == clean.size() - 1)
      day[clean[i].s] = clean[i].day;
    else{
      if (y == dp[clean[i+1].s]){
        day_min = min(day[clean[i+1].s], day[clean[i].e + 1] + clean[i].day);
        day[clean[i].s] = day_min;
      }
      else
        day[clean[i].s] = day[clean[i].e + 1] + clean[i].day;
    }
    return y;
  }
}

// in vector, Check day profit
void day_profit(vector<int>& dp, vector<int>& day) {
  for (int i = clean.size() - 1; i >= 0; i--) {
    int tmp = 0;
    if (i == clean.size() - 1)
      dp[clean[i].s] = clean_max(dp[clean[i].s + 1], dp[clean[i].e + 1] + clean[i].pay, i, dp, day);
    else {
      if (clean[i].s == clean[i + 1].s) {
        tmp = clean_max(dp[clean[i].s + 1], dp[clean[i].e + 1] + clean[i].pay, i, dp, day);
        if (tmp > dp[clean[i].s])
          dp[clean[i].s] = tmp;
      } else
        dp[clean[i].s] = clean_max(dp[clean[i].s + 1], dp[clean[i].e + 1] + clean[i].pay, i, dp, day);
    }
    if (i != 0) {
      for (int j = clean[i - 1].s + 1; j < clean[i].s; j++) {
        dp[j] = dp[clean[i].s];
        day[j] = day[clean[i].s];
      }
    }
  }
}

int main() {
  int n = 0, last = 0;
  int D, P;
  cin >> n;

  last = make_work(n);
  vector<int> dp(last + 2);
  vector<int> day(last + 2);
  day_profit(dp, day);

  P = *max_element(dp.begin(), dp.end());
  D = *max_element(day.begin(), day.end());
  cout << P + 10 << " " << D;

}
