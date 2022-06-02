#include "timebomb.h" // 0. 반드시 포함 . .
#include<bits/stdc++.h>

using namespace std;

vector<int> win;
int result;


void nextWinner(int N, int start) {
    for(int n=1; n<N; n+=2) {
        result = box_comp(win[start+n-1], win[start+n]); // 무게 비교 작업

        if(result == -1) { win.push_back(win[start+n]); }
        else if(result == 1) { win.push_back(win[start+n-1]); }
        else if(result == 0) break;
    }
}


int findSecond(int maxIdx) {
    int N = box_size(), winIdx, secondIdx, start=0;
    winIdx = maxIdx; // winIdx는 win벡터에서 maxIdx가 있는 위치

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
    int N; // 두번째로 무거운 박스 찾기
    int start=0, second;

    box_ready() ; // 1. 제일 먼저 호출해야 함.
    N = box_size( ) ; // 2. 갯수 확인 B[1]~B[N]

    // 제일 큰 수 찾기
    for(int m=1; m<N; m+=2) {
        result = box_comp(m, m+1); // 무게 비교 작업

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

    // 두 번째로 큰 수 찾기
    second = findSecond(win[start]);


    box_report(second) ; // 정답 보고, 종료됨 this는 폭탄 index
} // end of main( )
