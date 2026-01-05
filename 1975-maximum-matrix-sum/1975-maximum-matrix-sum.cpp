class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int neg=0;
        int minm=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int val=matrix[i][j];
                sum+=abs(val);
                if(val<0) neg++;
                minm=min(minm,abs(matrix[i][j]));
            }
        }
        if(neg%2!=0) sum-=2*minm;
        return sum;
    }
};