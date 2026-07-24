class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(char c:s){
            if(isalnum(c))
              temp += tolower(c);
        }
        int st=0,end=temp.size()-1;

        while(st<end){
            if(temp[st] != temp[end]) return false;
            st++;
            end--;
        }
        return true;
    }
};
