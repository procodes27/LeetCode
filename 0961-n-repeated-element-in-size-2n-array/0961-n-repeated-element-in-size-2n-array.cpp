class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int mid=nums.size()/2;
        if(nums[mid]==nums[mid+1]) return nums[mid];
        else return nums[mid-1];
        
    }
};