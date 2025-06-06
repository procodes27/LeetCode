class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> min_char(n);
        min_char[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i)
            min_char[i] = min(s[i], min_char[i + 1]);

        string t, p;
        for (int i = 0; i < n; ++i) {
            t.push_back(s[i]);
            while (!t.empty() && t.back() <= min_char[i + 1 == n ? n - 1 : i + 1]) {
                p.push_back(t.back());
                t.pop_back();
            }
        }
        while (!t.empty()) {
            p.push_back(t.back());
            t.pop_back();
        }
        return p;
    }
};
