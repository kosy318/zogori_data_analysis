#include<stdio.h>

int main()
{
    int N, Answer;
    scanf("%d",&N);
    if( N==3 ) Answer = 0;
    if( N==4 ) Answer = 1;
    if( N==5 || N==6 ) Answer = 2;
    if( N<=6 ){ printf("%d",Answer); return 0; }

    int last = 2, x = 6, lev=2;
    while( x <= N ){
        for( int j=1; j<=x; j++ ){
            int now = last + 1;
            if( j>lev ) now++;
            if( (x+j)==N ){
                printf("%d",now);
                return 0;
            }
        }
        x*=2;
        last += 2;
        lev*=2;
    }
    return 0;
}