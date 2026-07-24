class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<int,int> mp;
        int l=0;
        int r=0;
        int maxleng=0;
        while(r<n){
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l){
                l = mp[s[r]] + 1;
            }
            
            maxleng = max(maxleng , r-l+1);
            mp[s[r]] = r;
            r++;
        }
        return maxleng;
    }
};
