class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());


        int start=0;
        int end=0;
        int result=0;

        for(auto &m:meetings){
            if(m[0]>end) {
                result+=m[0]-end-1;
            }

            end=max(end,m[1]);

        }

            if(days>end) {
                result+=days-end;
            }
        

        return result;
    }
};