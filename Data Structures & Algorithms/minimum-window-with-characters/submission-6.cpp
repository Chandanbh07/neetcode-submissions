class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = t.size();
        int n2 = s.size();

        int l = 0, r = 0;
        int count=0;
        int minlen = INT_MAX;
        int s_idx = -1;

        vector<int> h(256,0);
        for(int c:t){
            h[c]++;
        }

        while(r < n2){
            if(h[s[r]] > 0) count++;

            h[s[r]]--;
            
            int len = r - l + 1;
            while(count == n1){
               if(len < minlen){
                 minlen = len;
                 s_idx = l;
               }

                h[s[l]]++;
                if(h[s[l]] > 0) count--;

                l++;

                len = r - l + 1;
            }

            r++;
        }
        if (s_idx == -1) return "";
        return s.substr(s_idx, minlen);
    }
};
