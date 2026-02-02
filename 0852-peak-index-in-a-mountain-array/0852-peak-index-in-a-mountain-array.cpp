class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n=arr.size();
        int maxel=arr[0];
        int maxin=arr[0];
        
        for(int i=0;i<n;i++){
            if(arr[i]>maxel){
                maxel=arr[i];
                maxin=i;
            }

        }
        return maxin;
    }
};