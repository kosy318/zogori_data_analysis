#include <bits/stdc++.h>
using namespace std;

int ns[1000001], n;

int main()
{
    ns[3] = 0;
    ns[4] = 1;

    for(int i = 5 ; i<=1000000 ; i++)
    {
        int k = i;
        if(i%2 == 1) k++;
        k/=2;
        ns[i] = ns[k]+2;
    }

    scanf("%d", &n);
    printf("%d\n",ns[n]);

    return 0;
}
