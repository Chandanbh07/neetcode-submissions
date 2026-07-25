class Solution {
public:
    string minWindow(string s, string t) {
        int n2 = s.size();
        int n1 = t.size();
        int minlen = INT_MAX;
        string ans = "";

        vector<int> h1(128,0);

        for(char c: t){
            h1[c]++;
        }

        for(int i=0; i<n2; i++){
            vector<int> h2(128,0);
            for(int j=i; j<n2 ; j++){
                h2[s[j]]++;

                int len = j-i+1;
                if(len >= n1 && isvalid(h1,h2)){
                    
                    if(len < minlen){
                        ans = s.substr(i,j-i+1);
                        minlen = len;
                    }
                }
            }
        }
        return ans;
    }

    bool isvalid(vector<int>& h1, vector<int>& h2){
        for(int i = 0 ; i < 128 ; i++){
            if(h1[i] > h2[i]) return false;
        }
        return true;
    }
};
