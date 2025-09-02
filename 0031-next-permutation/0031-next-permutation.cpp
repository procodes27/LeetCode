class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
int brk=-1;

       for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            brk=i;
            break;
        }
       }

       if(brk==-1){
        reverse(nums.begin(),nums.end());
        return;
       }
       for(int i=n-1;i>brk;i--){
        if(nums[i]>nums[brk]){
        swap(nums[i],nums[brk]);
        break;}
       }
       reverse(nums.begin()+brk+1,nums.end());

    }
};