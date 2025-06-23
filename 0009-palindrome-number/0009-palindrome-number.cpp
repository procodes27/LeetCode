class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long reverse=0;
        int temp=x;
        while(x){
            int rem=x%10;
            reverse=reverse*10+rem;
            x=x/10;

        }
        return reverse==temp;
    }
};