class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            int res = -1;

            for (int a = 0; a < x; a++) {
                if ((a | (a + 1)) == x) {
                    res = a;
                    break;
                }
            }

            ans.push_back(res);
        }

        return ans;
    }
};
