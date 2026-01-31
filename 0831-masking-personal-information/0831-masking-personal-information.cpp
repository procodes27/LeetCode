class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            for (char &c : s) c = tolower(c);
            return string(1, s[0]) + "*****" + s.substr(s.find('@') - 1);
        }
        string d;
        for (char c : s) if (isdigit(c)) d += c;
        string local = "***-***-" + d.substr(d.size() - 4);
        if (d.size() == 10) return local;
        return "+" + string(d.size() - 10, '*') + "-" + local;
    }
};
