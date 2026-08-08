class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        helper(candidates,target,curr,0);
        return ans;
    }

    void helper(vector<int>& candidates,int target, vector<int>& curr,int idx){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(idx == candidates.size() || target < 0){
            return;
        }

        for(int i = idx; i < candidates.size();i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            helper(candidates,target-candidates[i],curr,i+1);
            curr.pop_back();
        }
    }
};
