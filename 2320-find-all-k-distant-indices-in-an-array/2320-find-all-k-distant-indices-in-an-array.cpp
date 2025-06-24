class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> result;
        set<int>s;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                for(int j=0;j<n;j++){
                    if(abs(i-j)<=k) s.insert(j);
                }
            }
        }
        for(int a :s)
        result.push_back(a);
        return result;
    }
};