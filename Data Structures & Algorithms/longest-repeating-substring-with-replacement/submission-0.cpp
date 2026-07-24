class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0 , r=0 , maxfreq=0 , maxlen=0;
        int hash[26] = {0};
        int n = s.size();
        while(r < n){
            hash[s[r]-'A']++;

            maxfreq = max(maxfreq,hash[s[r]-'A']);

            int changes = (r-l+1) - maxfreq ;  // AAABB changes = 5 - 3 (A's freq)

            if(changes > k){
                hash[s[l]-'A']--; // remove start of window AAABBC remove A bcz k = 3
                l++;
            }
            else{
                maxlen = max(maxlen , r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
