class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n2 < n1) return false;

        vector<int> h1(26,0);
        for(char c:s1){
            h1[c-'a']++;
        }

        vector<int> h2(26,0);
        int left=0;
        int right=0;

        while(right < n2){
            while(right - left < n1){
                h2[s2[right]-'a']++;
                right++;
            }
            
            if(issame(h1,h2)) return true;

            h2[s2[left]-'a']--;
            left++;
        }
        return false;
    }

    bool issame(vector<int>& h1, vector<int>& h2){
        return h1 == h2;
    }
};
