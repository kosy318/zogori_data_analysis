#include <bits/stdc++.h>
using namespace std;
int main() {
    map<int, vector<array<int, 2>>> works;
    int count;
    cin >> count;
    int last = 0;
    for(int i=0; i<count; i++){
        int start, end, money;
        cin >> start >> end >> money;

        vector<array<int, 2>> vec = {{start, money}};
        if(works.count(end) == 0){
            works.insert(make_pair(end, vec));
        }
        else{
            works[end].push_back({start, money});
        }

        if(end > last){last = end;}
    }

    int table[last+1][2];
    table[0][0] = 0;
    table[0][1] = 0;
    table[1][0] = 0;
    table[1][1] = 0;

    for(int i=2; i<=last; i++){
        table[i][0] = table[i-1][0];
        table[i][1] = table[i-1][1];
        if(works.count(i) == 1){
            int temp[2] = {0,0};
            for(auto arr : works[i]){
                int money = arr[1] + table[arr[0]-1][1];
                int days = i - arr[0] + 1 + table[arr[0]-1][0];
                if(make_pair(money, -days) > make_pair(temp[1], -temp[0])){
                    temp[0] = days;
                    temp[1] = money;
                }
            }
            if(make_pair(temp[1] - 10, -temp[0]) > make_pair(table[i][1], -table[i][0])){
                table[i][0] = temp[0];
                table[i][1] = temp[1] - 10;
            }
        }
    }
    cout << table[last][1]+10 << " " << table[last][0];
}
