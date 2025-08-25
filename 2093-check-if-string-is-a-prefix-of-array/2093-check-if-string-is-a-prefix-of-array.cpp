class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        
        int n=s.length();
        string str="";

        for(int i=0;i<words.size();i++){
            if(str.length()<n && str!=s){
                str=str+words[i];
            }
            if(str==s) return true;
        }
        return false;
    }
};