class Solution {
public:
    string pushDominoes(string dominoes) {

        int n=dominoes.size();
        vector<int>right(n,0);
        vector<int>left(n,0);

        int force=0;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                force=n;
            }
            else if(dominoes[i]=='L'){
                force=0;
            }
            else{ force=max(force-1,0);

            }
            right[i]=force;
        }

        force=0;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                force=n;
            }
            else if(dominoes[i]=='R'){
                force=0;
            }
            else{
                force=max(force-1,0);
            }

            left[i]=force;
        }

        string result="";

        for(int i=0;i<n;i++){
            if(left[i]==right[i]) result+='.';
            else if(left[i]>right[i]) result+='L';
            else result+='R';

        }

        return result;
        
    }
};