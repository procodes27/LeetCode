class Solution {
public:
    bool isPowerOfTwo(int n) {
if(n==1|| n==2)
return true;
   while(n!=0){
            if(n%2!=0)
            return false;
            if(n==2 ){
                return true;
                break;
            }
            n=n/2;
           
        }
        return false;
        
    }
};