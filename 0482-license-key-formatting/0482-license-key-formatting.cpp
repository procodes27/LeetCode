class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t;
        for (char c : s) {
            if (c != '-') t += toupper(c);
        }

        string res;
        int cnt = 0;
        for (int i = t.size() - 1; i >= 0; i--) {
            res.push_back(t[i]);
            cnt++;
            if (cnt == k && i != 0) {
                res.push_back('-');
                cnt = 0;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
