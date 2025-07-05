class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int res=-1;

        for(auto &[num,freq]: mp){
            if(num==freq){
                res=max(res,num);
            }
        }

        return res;

        
    }
};