class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int result = 0;
        for (const auto& x : nums) {
            result |= x;
        }
        return result * pow(2, size(nums) - 1);
    }
};