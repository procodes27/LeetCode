class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int evncount=0;

        for(int i=0;i<n;i++){
            int count=0;
            int temp=nums[i];
            while(temp){
                temp=temp/10;
                count++;

            }
            if(count%2==0) evncount++;
            
            
        }
        return evncount;
        
    }
};