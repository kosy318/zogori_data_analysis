#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> breadMold;

void solve() {
    int a;
    for(a = 0; a < 2; ++a) {
        int i;
        for(i = 1; i < N+1 ; ++i) {
            if(breadMold[i-1]+1 != breadMold[i]) {
                int j;
                for(j = i+1 ; j < N+2; ++j) {
                    if(breadMold[i]*(-1)+1 == breadMold[j] ) {
                        for(int k = i; k <= (j+i-1)/2; k++) {
                            int temp = breadMold[k]*(-1);
                            breadMold[k] = breadMold[j-1-(k-i)]*(-1);
                            breadMold[j-1-(k-i)] = temp;
                        }

                        break;
                    }
                }

                if(j != N+2) break;
            }
        }
        
        for(i = 1; (i < N+1) && (i == breadMold[i]); ++i) ;
        if(i == N+1) break;
    }


    if(a == 0) cout << "one\n";
    else if(a == 1) cout << "two\n";
    else cout << "over\n";

    return;
}

void input() {
    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

    int k;
    cin >> N;
    for(int i = 0; i < 5; ++i) {
        breadMold.clear();
        breadMold.push_back(0);
        for(int j = 0; j < N; ++j) {
            cin >> k;
            breadMold.push_back(k);
        }
        breadMold.push_back(N+1);

        solve();
    }
}

int main()
{
    input();
    return 0;
}
