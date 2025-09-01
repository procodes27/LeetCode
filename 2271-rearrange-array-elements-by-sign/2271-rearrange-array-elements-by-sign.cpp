class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();

        vector<int>temp;

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                temp.push_back(nums[i]);
                temp.push_back(-1);
            }
        }
        int k=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                temp[k]=nums[i];
                k=k+2;
            }
        }
        
        return temp;
    }
};