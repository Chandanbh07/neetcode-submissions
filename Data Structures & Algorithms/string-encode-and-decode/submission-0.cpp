class Solution {
public:
    
    string encode(vector<string>& strs) {
        string s;
        for(string c:strs){
            s += to_string(c.size())+"#"+c;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        
        int i=0;
        while(i<s.size()){
            int j=i;

            while(s[j] != '#') j++;

            int len = stoi(s.substr(i,j-i));
            string word = s.substr(j+1,len);

            ans.push_back(word);
            i=j+1+len;
        }
        
        return ans;
    }
};
