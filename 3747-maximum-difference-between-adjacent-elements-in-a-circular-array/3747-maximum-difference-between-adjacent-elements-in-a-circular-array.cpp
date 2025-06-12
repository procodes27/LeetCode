class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

        int n=nums.size();
        int maxdiff=abs(nums[0] - nums[n-1]);
        

        for(int i=1;i<n;i++){
            maxdiff=max(maxdiff,abs(nums[i-1]-nums[i]));
        }
        return maxdiff;

        
    }
};