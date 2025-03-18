/*class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
    
        int mxm=1;
        int lnth=0;
        int i=0;
        int j=1;

        while(j<nums.size()){
            if((nums[i]&nums[j])==0){
                j++;
                lnth=j-i;
                mxm=max(mxm,lnth);
            }
            else{
                i++;
                j=i+1;
            }
           
        }
        return mxm;
    }
};*/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mxm=1;
        int lnth=1;  
        int i=0;
        int j=1;
        int usedBits=nums[i];  

        while (j<nums.size()) {
            if ((usedBits&nums[j])==0) {
                usedBits|=nums[j];
                j++;
                lnth=j-i;
                mxm=max(mxm,lnth);
            } else {
                usedBits^=nums[i];  
                i++;
            }
        }
        return mxm;
    }
};
