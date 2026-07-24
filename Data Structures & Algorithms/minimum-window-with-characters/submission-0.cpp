class Solution {
public:
    string minWindow(string s, string t) {
        int freq[256] = {0};
        int m = t.size();
        for(int i=0;i<t.size();i++){
            freq[t[i]]++;
        }

        int minlen = INT_MAX;
        int l=0, r=0;
        int count = 0;
        int stIdx = -1;

        while(r<s.size()){
            if(freq[s[r]] > 0) count++;
            freq[s[r]]--;

            while(count == m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    stIdx = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) count--;

                l++;
            }

            r++;
        }
        return (stIdx == -1) ? "" : s.substr(stIdx,minlen);
    }
};
