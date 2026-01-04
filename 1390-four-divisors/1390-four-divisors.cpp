class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            unordered_set<int> divs;
            divs.insert(1);
            divs.insert(n);

            for (int d = 2; d * d <= n; d++) {
                if (n % d == 0) {
                    divs.insert(d);
                    divs.insert(n / d);
                    if (divs.size() > 4) break;
                }
            }

            if (divs.size() == 4) {
                for (int x : divs) ans += x;
            }
        }

        return ans;
    }
};
