class Solution {
public:


bool allz(vector<int> counter){
    for(int &i : counter){
        if(i!=0) return false;
    }
    return true;
}
    vector<int> findAnagrams(string s, string p) {

        int n=s.length();

        vector<int> counter(26,0);

        for (char ch : p) {
            counter[ch - 'a']++;
        }

        int i=0;
        int j=0;
        int k=p.length();
        vector<int> cnt;


        while(j<n){
            counter[s[j]-'a']--;

            if(j-i+1==k){
                if(allz(counter)) cnt.push_back(i);
          
             counter[s[i]-'a']++;
             i++;


            }

            j++;
        }
        return cnt;
    }
};