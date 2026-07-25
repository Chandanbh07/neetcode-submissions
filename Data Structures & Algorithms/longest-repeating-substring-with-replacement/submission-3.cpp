class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int left=0;
        int right=0;
        int maxfreq=0;
        vector<int> hash(26,0);

        while(right < n){
            int freq = ++ hash[s[right]- 'A'];
            maxfreq = max(freq, maxfreq);

            int changes = right-left+1 - maxfreq;
            if(right-left+1 - maxfreq > k){
                hash[s[left]-'A']--;
                left++;
            }

            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};
