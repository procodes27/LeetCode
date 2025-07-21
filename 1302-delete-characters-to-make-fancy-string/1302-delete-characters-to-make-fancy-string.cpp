class Solution {
public:
    string makeFancyString(string s) {
        int n= s.length();
        string result="";

        result.push_back(s[0]);
        int freq=1;

        for(int i=1;i<n;i++){
            if(result.back()==s[i]){
                freq++;
                if(freq<3){
                    result.push_back(s[i]);
                }
            }

            else{
                result.push_back(s[i]);
                freq=1;
                
            }
        }
        return result;
    }
};