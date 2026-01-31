class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string t=s+s;
        return t.find(goal)!=string::npos;
    }
};