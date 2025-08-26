class Solution {
public:
    int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {
        int maxdiag= -1;
        int maxa = 0;

        for(const auto& rect:dimensions){
            int length=rect[0];
            int width=rect[1];

            int curr_diag = length*length+width*width;
            int curr_area = length*width;

            if (curr_diag>maxdiag){
                maxdiag=curr_diag;
                maxa = curr_area;
            } else if(curr_diag==maxdiag) {
                maxa=max(maxa, curr_area);
            }
        }

        return maxa;
    }
};