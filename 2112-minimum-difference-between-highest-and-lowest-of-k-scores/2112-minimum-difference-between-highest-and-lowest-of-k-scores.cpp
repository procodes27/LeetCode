class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1) return 0;

        sort(nums.begin(),nums.end());

        int mindiff=INT_MAX;

        for(int i=0;i<=n-k;i++){
            int currdiff=nums[i+k-1]-nums[i];
            if(currdiff<mindiff) mindiff=currdiff;
        }

        return mindiff;
        
    }
};