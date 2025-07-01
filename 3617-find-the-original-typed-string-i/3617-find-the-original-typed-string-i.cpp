class Solution {
public:
    int possibleStringCount(string word) {
        int i=0;
        int count =1;

        while(i<word.length()){
            if(word[i]==word[i+1]) count++;
            i++;
        }
        return count;
    }
};