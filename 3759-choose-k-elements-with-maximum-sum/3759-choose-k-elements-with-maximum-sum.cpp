class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> result(n, 0);
        vector<pair<int, int>> sortedNums1(n);
        
        for (int i = 0; i < n; i++) {
            sortedNums1[i] = {nums1[i], i};
        }
        sort(sortedNums1.begin(), sortedNums1.end());

        vector<pair<int, int>> indexedNums2(n);
        for (int i = 0; i < n; i++) {
            indexedNums2[i] = {nums2[i], nums1[i]};
        }
        sort(indexedNums2.begin(), indexedNums2.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            int currentValue = sortedNums1[i].first;
            int indexInResult = sortedNums1[i].second;

            while (j < n && indexedNums2[j].second < currentValue) {
                minHeap.push(indexedNums2[j].first);
                sum += indexedNums2[j].first;
                if (minHeap.size() > k) {
                    sum -= minHeap.top();
                    minHeap.pop();
                }
                j++;
            }

            result[indexInResult] = sum;
        }

        return result;
    }
};
