class Solution {
public:
    int findLHS(vector<int>& nums) {

        int n=nums.size();
        int mxlnth=0;
        int i=0;
        
        sort(nums.begin(),nums.end());

       for(int j=0;j<n;j++){
        
        while(nums[j]-nums[i]>1) i++;

        if(nums[j]-nums[i]==1){
            mxlnth=max(mxlnth,j-i+1);
        }
       }
        return mxlnth;  
    }
};