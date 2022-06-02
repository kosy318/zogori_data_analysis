#include <iostream>
#include <cstring>

using namespace std;
int dp[1000][1000] = {0,};
string dp_str[1000][1000];

void make_first_dp_str(string str, int i, int j){
	 if (dp[i][j-1] > dp[i+1][j]){
	 	dp_str[i][j] = dp_str[i][j-1];
	 }
	 else if (dp[i][j-1] < dp[i+1][j]){
	 	dp_str[i][j] = dp_str[i+1][j];
	 }
	 else{
	 	if (dp_str[i][j-1] < dp_str[i+1][j]){
	 		dp_str[i][j] = dp_str[i][j-1];
		 }
		 else{
		 	dp_str[i][j] = dp_str[i+1][j];
		 }
	 }
}

void plus_dp_str(string str, int i, int j){
	string str_plus;
	if (i != j && str[i] == str[j]) {
            dp[i][j] = dp[i+1][j-1] + 2;
            str_plus = "";
            str_plus += str[i];
            dp_str[i][j] = dp_str[i+1][j-1].insert(0,str_plus);
            
            str_plus = "";
            str_plus += str[i];
            dp_str[i][j] += str_plus;
	}
}
void make_dp(string str, int str_len){
    int i=0,j=0,gap=0;
    
    while(!(i == 0 && j == str_len)){
        //cout << i << " " << j << endl;
        if (i == j) {
           dp[i][j] = 1;
		   dp_str[i][j]	= str[i];
		}
        else {
        	 dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
  			 make_first_dp_str(str,i,j);
		}
        plus_dp_str(str,i,j);
        if (i != str_len-gap){
            i += 1;
            j = i + gap;
        }
        else{
            i = 0;
            gap += 1;
            j = i+gap;
        }

    }
    dp[0][str_len] = max(dp[0][str_len-1], dp[1][str_len]);
    make_first_dp_str(str,0,str_len);
    plus_dp_str(str,0,str_len);
        
    cout << dp_str[0][str_len];
    
}
int main()
{
    string all_str;
    int str_len;
    cin >> all_str;
    str_len = all_str.length()-1;

    make_dp(all_str,str_len);
    return 0;
}

