#include <iostream>
#include "timebomb.h"
#include <stack>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int N, result, th;
    map<int, vector<int>> max2;
    stack<int> win1;
    stack<int> win2;

    box_ready();
    N = box_size();

    int j = N;
    for(int i=1; i<N+1; i++){
        if(i >= j) break;
        result = box_comp(i,j);
        if(result == 1){//i>j
            win1.push(i);
            max2[i].push_back(j);

        }
        else if(result == -1) {//i<j
            win1.push(j);
            max2[j].push_back(i);
        }
        j--;
    }

    //cout<< 1 <<endl;
    int m,n, x, y;
    while(true){

    while(!win1.empty()){
        m = win1.top();
        win1.pop();

        if(win1.empty()){
            win2.push(m);
            break;
        }

        n = win1.top();
        win1.pop();

        //cout<< m <<endl;
        //cout<< n <<endl;

        result = box_comp(m,n);
        if(result == 1){
            win2.push(m);
            max2[m].push_back(n);
        }
        else if(result == -1) {
            win2.push(n);
             max2[n].push_back(m);
        }
    }

    if(win2.size()==1) break;

    while(!win2.empty()){
        x = win2.top();
        win1.push(x);
        win2.pop();
    }

    }

    //cout<< 2 <<endl;
    y = win2.top();
    //cout<< y <<endl;

    int z = max2[y].size();
    for(int i=0; i<z; i++){
        win1.push(max2[y][i]);
        //cout<< i <<endl;
    }

    m = win1.top();
    win1.pop();
    while(!win1.empty()){
        n = win1.top();
        win1.pop();
        result = box_comp(m,n);
        if(result == 1){
            th = m;
        }
        else if(result == -1) {
            th = n;
            m = n;
        }
    }

    //cout<< 3 <<endl;
    //cout<< th <<endl;

    box_report(th);

    return 0;
}
