#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
       vector<int> cnt(n+1,0);

        for (int x : nums) cnt[x]++;

        for (int i = 1; i <= n; i++)
            if (cnt[i] == 2) 
                for (int j = 1; j <= n; j++)
                    if (cnt[j] == 0)
                        return {i, j};

        return {};
    }
};
