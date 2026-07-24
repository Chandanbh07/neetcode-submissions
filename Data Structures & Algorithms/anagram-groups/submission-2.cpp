class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> mp;

       for(string st: strs){
         string val = st;
         sort(val.begin(),val.end());

         mp[val].push_back(st);
       }

       vector<vector<string>> ans;
       for(auto& [key,group]: mp){
        ans.push_back(group);
       }

       return ans;
    }
};
