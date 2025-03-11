class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        double mxavg = INT_MIN;

         for(int i=0;i<k;i++){
            sum+=nums[i];
        }

         mxavg=sum/k;

        for(int i=k;i<n;i++){
             sum+=nums[i]-nums[i-k];     
             mxavg=max(mxavg,sum/k);
        }

    return mxavg;
    }

};