class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> sp;
        int mxm=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(abs(nums[j]-nums[i])<=min(nums[j],nums[i]))

                sp.push_back({nums[i],nums[j]});
            }
        }

        for(int i=0;i<sp.size();i++){
            mxm=max(mxm,sp[i].first^sp[i].second);
        }

        return mxm;
        
    }
};