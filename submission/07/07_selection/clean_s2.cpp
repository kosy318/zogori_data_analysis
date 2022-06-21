#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Work {  
    int b, e, c;
};

struct Data {
    int lastDate;
    int pay;
    int workingDays;
};

int main()
{
    int N;
    
    cin >> N;

    vector<Work> works(N);
    
    vector<Data> dp(N);

    for(int i = 0; i < N; i++) {
        cin >> works[i].b >> works[i].e >> works[i].c;
    }
    
    sort(works.begin(), works.end(), [](const Work& a, const Work& b)
            {
                return a.b == b.b ? a.e < b.e : a.b < b.b;
            });
            
    for(int i = 0; i < N; i++) {
        dp[i].lastDate = works[i].e;
        dp[i].pay = works[i].c;
        dp[i].workingDays = works[i].e - works[i].b + 1;
    }       

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j].lastDate < works[i].b 
            && (dp[i].pay < dp[j].pay + works[i].c - 10 
            || dp[i].pay == dp[j].pay + works[i].c - 10 && dp[i].workingDays > dp[j].workingDays + works[i].e - works[i].b + 1)) {    
                dp[i].lastDate = works[i].e;
                dp[i].pay = dp[j].pay + works[i].c - 10;
                dp[i].workingDays = dp[j].workingDays + works[i].e - works[i].b + 1;
            }
        }
    }

    Data bestData = dp[0];
    
    for(int i = 0; i < N; i++)  
        if(dp[i].pay > bestData.pay || (dp[i].pay == bestData.pay && bestData.workingDays > dp[i].workingDays))
            bestData = dp[i];
        
    cout << bestData.pay << " " << bestData.workingDays << endl;
    
    return 0;
}