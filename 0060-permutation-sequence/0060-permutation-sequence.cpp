class Solution {
public:
    string getPermutation(int n, int k) {
    
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }

        vector<int> numbers;
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }

        k--;

        string result = "";
        for (int i = n; i >= 1; i--) {
            int blockSize = fact[i - 1];
            int index = k / blockSize;

            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);

            k %= blockSize;
        }

        return result;
    }
};
