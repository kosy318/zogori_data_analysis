#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[101][101] = {0,};
string dp_str[101][101];
struct comp_str{
	string str_c;
	int int_c; 
};
bool comp(comp_str s1, comp_str s2){
	if (s1.int_c == s2.int_c){
        return s1.str_c > s2.str_c;
    }
    return s1.int_c < s2.int_c;
}
int main(void){
	string s1, s2;
	cin >> s1 >> s2;
	int s1_len = s1.length();
	int s2_len = s2.length();
	int max_dp = 0;
	string max_str;
	
	
	for (int i=0; i<s2_len+1; i++){
		for (int j=0; j<s1_len+1; j++){
			if (i==0 || j==0) dp[i][j] = 0;
			else{
				if (s1[j-1]==s2[i-1]){
					int a,b,c,d;
					string as,bs,cs,ds;
					a=1, b=1, c=1, d=1;
					as = s1[j-1], bs = s1[j-1], cs=s1[j-1], ds = s1[j-1];
					if (i >= 2 && j >= 2){
						a = dp[i-2][j-2]+1;
						as = dp_str[i-2][j-2]+s1[j-1];
					}
					if (i >= 2 && j >= 3){
						b = dp[i-2][j-3]+1;
						bs = dp_str[i-2][j-3]+s1[j-1];
				    }
				    if (i >= 3 && j >= 2){
						c = dp[i-3][j-2]+1;
						cs = dp_str[i-3][j-2]+s1[j-1];
				    }
				    if (i >= 3 && j >= 3){
						d = dp[i-3][j-3]+1;
						ds = dp_str[i-3][j-3]+s1[j-1];
				    }
				
					comp_str COM[4];
					COM[0].str_c = as, COM[0].int_c = a;
					COM[1].str_c = bs, COM[1].int_c = b;
					COM[2].str_c = cs, COM[2].int_c = c;
					COM[3].str_c = ds, COM[3].int_c = d;
					
					sort(COM, COM+4, comp);
					dp[i-1][j-1] = COM[3].int_c;
					dp_str[i-1][j-1] = COM[3].str_c;
			//		cout << dp[i-1][j-1] << " ";
					if (max_dp < dp[i-1][j-1]) {
					   max_dp = dp[i-1][j-1];
					   max_str = dp_str[i-1][j-1];	
					}
					if (max_dp == dp[i-1][j-1]){
						if (max_str > dp_str[i-1][j-1])
						   max_str = dp_str[i-1][j-1];
					}
				}
			}
		//	cout << i << " "<< j << " " <<  dp[i-1][j-1] << endl;
		}
	//	cout << endl;
	}
	cout << max_str << endl;
	return 0;
}
