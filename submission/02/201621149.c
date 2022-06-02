#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[10002], t[10002];
int isfind = 0;

void check(int s_idx, int t_idx){
    if (t_idx == strlen(t)){
        // printf("<%d>\n", (strlen(s) - s_idx));
        if ((strlen(s) - s_idx) %2 == 0)
            isfind = 1;
        return;
    }

    char *pch = strchr(s+s_idx, t[t_idx]);
    while(pch != NULL){
        if (s_idx == 0 || (pch - s - s_idx)%2 == 0){
            // printf("s:%d & t:%d[%c]\n", pch - s + 1, t_idx, t[t_idx]);
            check(pch - s + 1, t_idx + 1);
        }

        pch = strchr(pch+1, t[t_idx]);


        if (isfind)
            break;
    }
}

int main(){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        isfind = 0;

        scanf("%s", s);
        scanf("%s", t);

        // printf("%s & %s\n", s, t);
        check(0, 0);
        if (isfind)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
