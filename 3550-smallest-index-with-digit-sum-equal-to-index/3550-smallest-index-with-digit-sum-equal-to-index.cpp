class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int dsum=0;
            int val=nums[i];
            while(val>0){
                int rem=val%10;
                dsum=dsum+rem;
                val=val/10;

            }
            if(dsum==i) return i;
        }
        return -1;
    }
};