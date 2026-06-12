#include <bits/stdc++.h>
using namespace std;

class CountSquares {
   private:
    unordered_map<int, unordered_map<int, int>> rows;

   public:
    CountSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        rows[y][x]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        long long ans = 0;

        if (!rows.count(y)) return 0;

        for (auto& entry : rows[y]) {
            int x2 = entry.first;
            int freqSameRow = entry.second;

            if (x2 == x) continue;

            int d = abs(x2 - x);

            if (rows.count(y + d)) {
                long long c1 = rows[y + d].count(x) ? rows[y + d][x] : 0;
                long long c2 = rows[y + d].count(x2) ? rows[y + d][x2] : 0;
                ans += 1LL * freqSameRow * c1 * c2;
            }

            if (rows.count(y - d)) {
                long long c1 = rows[y - d].count(x) ? rows[y - d][x] : 0;
                long long c2 = rows[y - d].count(x2) ? rows[y - d][x2] : 0;
                ans += 1LL * freqSameRow * c1 * c2;
            }
        }

        return (int)ans;
    }
};