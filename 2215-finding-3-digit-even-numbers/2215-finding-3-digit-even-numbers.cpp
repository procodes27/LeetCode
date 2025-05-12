class Solution {
public:
   vector<int> findEvenNumbers(vector<int>& digits) {

    set<int> result;

    int n = digits.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            
            if (j == i) continue;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                int d1 = digits[i];
                int d2 = digits[j];
                int d3 = digits[k];
                if (d1 == 0) continue;
                if (d3 % 2 != 0) continue;
                int num = d1 * 100 + d2 * 10 + d3;
                result.insert(num);
            }
        }
    }
    vector<int>ans(result.begin(),result.end());
   
return ans;
}

};