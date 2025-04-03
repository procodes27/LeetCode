class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxValue = 0;

        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);

        maxLeft[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
        }

        maxRight[n - 1] = nums[n - 1];
        for (int k = n - 2; k >= 0; k--) {
            maxRight[k] = max(maxRight[k + 1], nums[k]);
        }

        for (int j = 1; j < n - 1; j++) {
            long long value = (long long)(maxLeft[j - 1] - nums[j]) * maxRight[j + 1];
            maxValue = max(maxValue, value);
        }

        return maxValue;
    }
};
