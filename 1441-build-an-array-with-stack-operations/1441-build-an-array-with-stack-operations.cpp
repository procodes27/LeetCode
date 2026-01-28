class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int idx = 0;

        for (int num = 1; num <= n && idx < target.size(); num++) {
            ops.push_back("Push");

            if (num == target[idx]) {
                idx++;  
            } else {
                ops.push_back("Pop");
            }
        }

        return ops;
    }
};
