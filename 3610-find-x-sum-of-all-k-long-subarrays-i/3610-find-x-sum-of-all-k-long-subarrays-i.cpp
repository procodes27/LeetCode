class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i <= n - k; ++i) {
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            result.push_back(x_sum_of_subarray(subarray, x));
        }

        return result;
    }

private:
    int x_sum_of_subarray(const vector<int>& subarray, int x) {
        unordered_map<int, int> freq_map;

        for (int num : subarray) {
            freq_map[num]++;
        }
        vector<pair<int, int>> freq_vector;
        for (const auto& pair : freq_map) {
            freq_vector.push_back(pair);
        }
        sort(freq_vector.begin(), freq_vector.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second > b.second;
        });

        int x_sum = 0;
        for (int i = 0; i < x && i < freq_vector.size(); ++i) {
            x_sum += freq_vector[i].first * freq_vector[i].second;
        }
        if (freq_vector.size() < x) {
            x_sum = 0;
            for (int num : subarray) {
                x_sum += num;
            }
        }

        return x_sum;
    }
};