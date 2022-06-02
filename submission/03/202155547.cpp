#include <iostream>
#include <algorithm>

using namespace std;

int flip_times(int fish[], int k)
{
    int cnt=0;
    for (int i=0; i<k; i++)
    {
        if (fish[i] != i+1) {
            if (fish[i] > 0) return 0;
            else if (fish[i] < 0 && fish[i+1] < 0){
                 if (fish[i+1] - fish[i] != 1) return 0;
            }
            else cnt += 1;
        }
    }
    if (cnt == 1) return 1;
    if (cnt == 2) return 2;
    return 0;
}

int flip_twice(int fish[], int k)
{
    int start=-1, finish=k-1;

    for (int i=0; i<k; i++){
        if (fish[i] != i+1){
            if (fish[i] > 0){
                if (start == -1) start = i;
                for (int j=i; j<k; j++){
                    if (fish[j] < 0)
                        if (fish[j+1] - fish[j] != 1){
                            finish = j;
                            break;
                        }
                    if (fish[j] == j+1) {
                        finish = j-1;
                        break;
                    }
                }
                break;
            }
            if (fish[i]-fish[i-1] != 1) start = i;
        }
    }
    for (int i=0; i<=(finish-start)/2; i++){
        int temp = fish[start+i];
        fish[start+i] = fish[finish-i]*(-1);
        fish[finish-i] = temp*(-1);
    }

    if (flip_times(fish,k) == 1) return 2;
    return 0;
}

int fish_bread(int n)
{
    int fish[10000];
    int temp, temp2;

    for (int i=0; i<n; i++)
    {
        cin >> fish[i];
    }
    temp = flip_times(fish, n);
    if (temp > 0) return temp;
    temp2 = flip_twice(fish,n);
    return temp2;

}
int main()
{
    int k, ans;
    cin >> k;

    for (int i=0; i<5; i++)
    {
        ans = fish_bread(k);
        if (ans == 1) cout << "one" << endl;
        else if (ans == 2) cout << "two" << endl;
        else cout << "over" << endl;
    }
    return 0;
}
