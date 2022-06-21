#include "timebomb.h"
#include <vector>

using namespace std;

vector<int> find_max(vector<int> v, int start, int end) {
    vector<int> trace;
    if (start == end) {
        trace.push_back(start);
        return trace;
    }
    else if (start == end-1) {
        if (box_comp(v[start]+1, v[end]+1) == 1) {
            trace.push_back(end);
            trace.push_back(start);
        } else {
            trace.push_back(start);
            trace.push_back(end);
        }
        return trace;
    }
    else {
        int mid = (start + end) / 2;
        vector<int> traceA = find_max(v, start, mid);
        vector<int> traceB = find_max(v, mid+1, end);
        int a = traceA.back();
        int b = traceB.back();
        if (box_comp(v[a]+1, v[b]+1) == 1) {
            traceA.pop_back();
            traceA.push_back(b);
            traceA.push_back(a);
            trace = traceA;
        } else {
            traceB.pop_back();
            traceB.push_back(a);
            traceB.push_back(b);
            trace = traceB;
        }
        return trace;
    }
}

int main() {
    int N;
    box_ready();
    N = box_size();

    vector<int> v(N);
    for (int i=0; i<N; i++) v[i] = i;

    vector<int> trace = find_max(v, 0, N-1);
    trace.pop_back();

    int bomb = trace[find_max(trace, 0, trace.size()-1).back()] + 1;

    box_report(bomb);
}
