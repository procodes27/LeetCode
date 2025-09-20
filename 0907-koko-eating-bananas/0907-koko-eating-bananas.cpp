#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findmx(const vector<int>& v) {
        int maxm = INT_MIN;
        for (int x : v) {
            maxm = max(maxm, x);
        }
        return maxm;
    }

    long long totalhour(const vector<int>& v, int hrly) {
        long long totalh = 0;
        for (int x : v) {
            totalh += (x + hrly - 1LL) / hrly;
        }
        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmx(piles);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalh = totalhour(piles, mid);
            if (totalh <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
