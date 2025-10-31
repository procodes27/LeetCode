class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> result;

        for (int num : nums) {
            count[num]++;
        }

        for (const auto& pair : count) {
            if (pair.second == 2) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};