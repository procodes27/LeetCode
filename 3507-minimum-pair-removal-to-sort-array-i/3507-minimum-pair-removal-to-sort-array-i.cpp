class Solution {
public:

bool isnd(const vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[i-1]) return false;
        
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        int op=0;

        while(!isnd(nums)){
            int mins=INT_MAX;
            int index=0;

            for(int i=0;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];
                if(sum<mins){
                    mins=sum;
                    index=i;
                }
            }
            vector<int> temp;
            for(int i=0;i<nums.size();i++){
            if(i==index){
                temp.push_back(nums[i]+nums[i+1]);
                i++;
            } 
            else{
                temp.push_back(nums[i]);
            }
            
        }
        nums=temp;
        op++;
        }
        return op;
    }
};