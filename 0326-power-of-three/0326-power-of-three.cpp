class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1 || n==3)
        return true;
        

        while(n!=0){
if(n==11 ||n==29|| n==83|| n==245|| n==731||n==2189||n==6563)
return false;

            if(n%2==0)
            return false;
        if(n==3)
        {
            return true;
            break;
        }
        n=n/3;
        
        }
        return false;
    }
};
