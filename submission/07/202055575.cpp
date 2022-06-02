#include <bits/stdc++.h>

using namespace std;
int N;

class work{
public:
    int begin; int end;
    int weight; int term;
    work(){}
    work(int b, int e, int w){
        this->begin = b; 
        this->end =e;
        this->weight =w; 
        this->term = e-b +1;
    }
    work(int b, int e, int w, int t){
        this->begin = b; 
        this->end =e;
        this->weight =w; 
        this->term = t;
    }
    bool operator< (work& other){
        if(this->end < other.end) return true;
        if(this->end == other.end){
            if(this->begin < other.begin) return true;
            if(this->begin == other.begin){
                return this->weight > other.weight;
            }
            else return false;
        }
        else return false;
    }


    work operator+ (work other){
        int b = this->begin,e = this->end,w = this->weight+other.weight,t=this->term + other.term;
        if(this->begin > other.begin) b = other.begin;
        if(this->end < other.end) e = other.end;
        return work(b,e,w-10,t);
    }
};

vector<work> schedule;

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        int b,e,w;
        cin >> b >> e >> w;
        schedule.push_back(work(b,e,w));
    }
}

void sort_works(){
    sort(schedule.begin(),schedule.end());
}

work& comp_pd(work& a, work& b){
    if(a.weight > b.weight) return a;
    if(a.weight == b.weight && a.term < b.term) return a;
    else return b;
}

vector<work> table;

work dp(int sc_index){
    if(table[sc_index].weight != 0) return table[sc_index];

    work a = schedule[sc_index];
    work b;

    if(sc_index <= 0) b= schedule[sc_index];
    else{
        b = dp(sc_index-1);
        int i=sc_index-1;
        while(schedule[i].end >= schedule[sc_index].begin){
            i--;
            if(i<0) break;
        }
        if(i>=0) a = a+dp(i);
    }
    work c = comp_pd(a,b);
    table[sc_index] = c;
    return c;
}

int main(){
    input();
    sort_works();
    table.resize(N,work(0,0,0));
    cout <<dp(N-1).weight << " " << dp(N-1).term;
}