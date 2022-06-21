#include "timebomb.h"
#include <vector>

using namespace std;

vector<int> vc;
vector<vector<int>> record;

void set_vc(int N){
    for(int i=1; i <= N; i++){
        vc.push_back(i);
    }

}

int main(){
    int N, result, ans;

    box_ready();
    N = box_size();
    vector<int> temp_vc;
    record.clear();
    record.resize(N+2);

    set_vc(N);

    while(vc.size()!=2){
        temp_vc.clear();    
        for(int i=0; i<vc.size(); i+=2){
            if(i+1==vc.size()) {
                temp_vc.push_back(vc[i]);
                continue;
            }if(box_comp(vc[i],vc[i+1])>=0){
                temp_vc.push_back(vc[i]);
                record[vc[i]].push_back(vc[i+1]);
            }else{
                temp_vc.push_back(vc[i+1]);
                record[vc[i+1]].push_back(vc[i]);
            }
        }
        vc.clear(); vc = temp_vc;
    }
    
    int max_index, second_index;

    if(box_comp(vc[0],vc[1])>0) {
        max_index = vc[0];
        record[max_index].push_back(vc[1]); }
    else{                       
        max_index = vc[1]; 
        record[max_index].push_back(vc[0]); }
    
    second_index = 0;
    for(int i=1; i<record[max_index].size(); i++){
        if(box_comp(record[max_index][i],record[max_index][second_index])>0){
            second_index = i;
        }
    }

    box_report(record[max_index][second_index]);
}