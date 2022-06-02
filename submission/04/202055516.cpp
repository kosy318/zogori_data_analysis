#include "timebomb.h" // 0. �ݵ�� ���� . .
#include<bits/stdc++.h>

using namespace std;

vector<int> win;
int result;


void nextWinner(int N, int start) {
    for(int n=1; n<N; n+=2) {
        result = box_comp(win[start+n-1], win[start+n]); // ���� �� �۾�

        if(result == -1) { win.push_back(win[start+n]); }
        else if(result == 1) { win.push_back(win[start+n-1]); }
        else if(result == 0) break;
    }
}


int findSecond(int maxIdx) {
    int N = box_size(), winIdx, secondIdx, start=0;
    winIdx = maxIdx; // winIdx�� win���Ϳ��� maxIdx�� �ִ� ��ġ

    if(maxIdx%2==1 && maxIdx==N) secondIdx=1;
    else if(maxIdx%2==1) secondIdx = maxIdx+1;
    else secondIdx = maxIdx-1;
    winIdx -= 1;

    while(N>2) {
        if(winIdx==0) winIdx=0;
        else winIdx = winIdx/2;

        if(winIdx%2==1) {
            result = box_comp(secondIdx, win[start+winIdx-1]);
            if(result == -1) { secondIdx=win[start+winIdx-1]; }
            else if(result == 0) break;
        }

        else {
            result = box_comp(secondIdx, win[start+winIdx+1]);
            if(result == -1) { secondIdx=win[start+winIdx+1]; }
            else if(result == 0) break;
        }

        if(N%2==1) { N=N/2+1;start+=N;}
        else { N = N/2;start+=N; }

    }
    return secondIdx;
}

int main() {
    int N; // �ι�°�� ���ſ� �ڽ� ã��
    int start=0, second;

    box_ready() ; // 1. ���� ���� ȣ���ؾ� ��.
    N = box_size( ) ; // 2. ���� Ȯ�� B[1]~B[N]

    // ���� ū �� ã��
    for(int m=1; m<N; m+=2) {
        result = box_comp(m, m+1); // ���� �� �۾�

        if(result == -1) { win.push_back(m+1); }
        else if(result == 1) { win.push_back(m); }
        else if(result == 0) break;
    }
    if(N%2==1) { win.push_back(N); N=N/2+1; }
    else { N = N/2; }

    while(N>1) {
        nextWinner(N, start);
        if(N%2==1) {
            win.push_back(win[start+N-1]);
            start+=N; N=N/2+1;
            }
        else { start+=N; N = N/2; }
    }

    // �� ��°�� ū �� ã��
    second = findSecond(win[start]);


    box_report(second) ; // ���� ����, ����� this�� ��ź index
} // end of main( )
