#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

const int SIZE = 1001;
int dp[SIZE];
bool chk[SIZE];

void init() {
    for(int i=0; i<SIZE; i++) chk[i] = false;
}

void preprocessing()
{
    dp[0] = 1;
    dp[1] = 1;

    int k, val;

    for(int i=2; i<SIZE; i++) {
        k = 1;
        init();

        while(i - 2 * k >= 0)
        {
            val = 2 * dp[i - k] - dp[i - 2 * k];
            if(val > 0) {
                chk[val] = true;
                // printf("val : %d k : %d \n", val, k);
            }
            k++;

        }

        for(int j=1 ;j<1001; j++) {
            if(!chk[j]) {
                dp[i] = j;
                break;
            }
        }
    }
}

int main(void)
{
    preprocessing();

    int n;
    scanf("%d", &n);

    printf("%d", dp[n]);

    return 0;
}