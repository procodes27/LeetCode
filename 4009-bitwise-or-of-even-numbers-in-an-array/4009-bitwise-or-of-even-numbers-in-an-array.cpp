class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int bor=0;
        int n=nums.size();
        for(int x:nums){
            if(x%2==0){
                bor|=x;
            }
        }
        return bor;
        
    }
};