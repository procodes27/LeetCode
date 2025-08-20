class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
     sort(buses.begin(),buses.end());
     sort(passengers.begin(),passengers.end());

     int n=buses.size();
     int m=passengers.size();

     int i=0;
     
     int cand=-1;

     for(int b=0;b<n;b++){
        int count=0;

        while(i<m && passengers[i]<=buses[b] && count<capacity ){
            i++;
            count++;
        }

        if(b==n-1){
            if(count<capacity){
                cand=buses[b];
            }
            else{
                cand=passengers[i-1]-1;
            }
        }
     }

     unordered_set<int> passengerSet(passengers.begin(),passengers.end());

        while(passengerSet.count(cand)){
            cand--;
        }

     
return cand;

    }
};