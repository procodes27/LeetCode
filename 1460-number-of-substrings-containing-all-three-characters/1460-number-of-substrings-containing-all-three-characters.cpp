class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        unordered_map<char,int>mp;
        int i=0;
        int count =0;

        for(int j=0;j<n;j++){
            mp[s[j]]++;

            while(mp.size()==3){
                count+=n-j;

                mp[s[i]]--;
                if(mp[s[i]]==0){
                   mp.erase(s[i]);
                   
                }
                i++;
            }
        }
        return count;
    }
};