class Solution {
public:
    vector<vector<string>> ans;

    bool is_palin(string s, int st, int end){
        while(st < end){
            if(s[st] != s[end]) return false;
            st++;
            end--;
        }
        return true;
    }

    void helper(string s, vector<string>& pal, int st, int end){
        if(st == s.size()){
            ans.push_back(pal);
            return;
        }

        for(int i = st+1; i<=s.size(); i++){
            if(is_palin(s,st,i-1)){
                int len = i-st;
                pal.push_back(s.substr(st,len));
                helper(s,pal,i,end);
                pal.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> pal;
        helper(s,pal,0,s.size()-1);
        return ans;
    }
};
