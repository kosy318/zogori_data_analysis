#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> endDateInfo(365*3+1, std::vector<std::pair<int, int>>());

    for (int i=0; i<n; i++) {
        int beginDate, endDate, cost;

        std::cin >> beginDate >> endDate >> cost;
        endDateInfo[endDate].push_back({beginDate, cost});
    }

    std::vector<std::pair<int, int>> table(365*3+1, {0, 0}); // table[i].first == cost, table[i].second == work date

    for (int endDate=1; endDate<=365*3; endDate++) {
        table[endDate] = table[endDate-1];
        for (int i=0; i<endDateInfo[endDate].size(); i++) {
            auto current = endDateInfo[endDate][i];
            int beginDate = current.first;
            int cost = current.second;
            if (table[beginDate-1].second != 0) {
                cost -= 10;
            }
            int workDate = endDate-beginDate+1;

            if (table[beginDate-1].first + cost > table[endDate].first 
                || table[beginDate-1].first + cost == table[endDate].first
                && table[beginDate-1].second + workDate < table[endDate].second) {
                table[endDate] = {table[beginDate-1].first + cost, table[beginDate-1].second + workDate};
            }
        }
    }

    std::cout << table[365*3].first << " " << table[365*3].second;

    return 0;
}