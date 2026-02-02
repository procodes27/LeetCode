class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> even(n,0), odd(n,0);

        for(int i=0;i<n;i++){
            if(i>0){
                even[i] = even[i-1];
                odd[i] = odd[i-1];
            }
            if(i%2==0) even[i]+=nums[i];
            else odd[i]+=nums[i];
        }

        int totalEven = even[n-1];
        int totalOdd = odd[n-1];
        int ans = 0;

        for(int i=0;i<n;i++){
            int leftEven = (i>0)? even[i-1] : 0;
            int leftOdd  = (i>0)? odd[i-1] : 0;

            int rightEven = totalOdd - odd[i];
            int rightOdd  = totalEven - even[i];

            if(leftEven + rightEven == leftOdd + rightOdd)
                ans++;
        }
        return ans;
    }
};
