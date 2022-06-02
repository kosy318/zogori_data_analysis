#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct clean
{
    int start_day, finish_day, profit;
};
struct answer
{
    int pro_max, day_min;
} typedef answer;
bool comparator(clean j1, clean j2)
{
    if (j1.start_day == j2.start_day){
        return j1.finish_day<j2.finish_day;
    }
    return j1.start_day<j2.start_day;
}
void get_input(clean* cleaning)
{
    cin >> cleaning->start_day;
    cin >> cleaning->finish_day;
    cin >> cleaning->profit;
}
void copy_clean(clean * job1, clean * job2)
{
	job1->start_day  = job2->start_day;
	job1->finish_day = job2->finish_day;
	job1->profit     = job2->profit;
}
answer find_max(clean job[100], int n)
{
    int max_profit[100], min_day[100];
    
    max_profit[0] = job[0].profit;
    min_day[0]    = job[0].finish_day - job[0].start_day + 1;
    
    int included, not_included;
    int include_day, not_include_day,j;
    
    for (int i=1; i<n; i++){
    	// case1
        included    = job[i].profit;
        include_day = job[i].finish_day - job[i].start_day + 1;
        clean not_conflicting_job[100];
        int k=0;
        for (int j=0; j<i; j++){
            if (job[j].finish_day < job[i].start_day){
                copy_clean(&not_conflicting_job[k], &job[j]);
                k += 1;
            }
        }
        if (k>0) {
            answer ans_recur;
            ans_recur = find_max(not_conflicting_job, k);
            if (ans_recur.pro_max > 10){
                included    += ans_recur.pro_max-10;
                include_day += ans_recur.day_min;
            }
        }
        //case2
        not_included    = max_profit[i-1];
        not_include_day = min_day[i-1];
        
		if (included == not_included){
            max_profit[i] = included;
            if (include_day < not_include_day){
                min_day[i] = include_day;
            }
            else{
                min_day[i] = not_include_day;
            }
        }
        else if (included < not_included){
            max_profit[i] = not_included;
            min_day[i]    = not_include_day;

        }
        else{
            max_profit[i] = included;
            min_day[i]    = include_day;
        }
    }
    answer ans;
    ans.pro_max = max_profit[n-1];
    ans.day_min = min_day[n-1];
    return ans;
}
int main()
{
    int n;
    cin >> n;
    clean clean_arr[100];
    for (int i=0; i<n; i++){
        get_input(&clean_arr[i]);
    }
    sort(clean_arr, clean_arr+n, comparator);
    answer ans_final;
    ans_final = find_max(clean_arr, n);
    cout << ans_final.pro_max << " " << ans_final.day_min;
    return 0;
}
