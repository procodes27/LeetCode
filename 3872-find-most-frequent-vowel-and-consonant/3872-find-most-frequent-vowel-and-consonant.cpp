class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        for(char c : s) freq[c-'a']++;

        string vow="aeiou";
        int maxvow=0;
        int maxcon=0;

        for(int i=0;i<26;i++){
            char c='a'+i;

            if(freq[i]==0) continue;

            if(vow.find(c)!=string::npos){
                maxvow=max(maxvow,freq[i]);
            }
            else{
                maxcon=max(maxcon,freq[i]);
            }
        }
        return maxvow+maxcon;
    }
};