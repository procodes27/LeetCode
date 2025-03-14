class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        int start=1,end=*max_element(candies.begin(),candies.end());
        int result=0;

        while(start<=end){
            int mid=start+(end-start)/2;
            long long total=0;

            for(int candy:candies){
                total+=candy/mid;
            }

            if(total>=k){
                result=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return result;
    }
};