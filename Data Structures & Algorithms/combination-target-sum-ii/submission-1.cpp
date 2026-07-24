class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        helper(candidates,target,n-1,cur);
        return ans;
    }

    void helper(vector<int>& candidates, int target ,int idx , vector<int>& cur ){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if(target < 0 || idx < 0) return;

        cur.push_back(candidates[idx]);
        helper(candidates,target - candidates[idx] , idx-1 , cur);
        cur.pop_back();

        int newIdx = idx-1;
        while(newIdx >= 0 && candidates[newIdx] == candidates[idx]){
            newIdx--;
        }
        helper(candidates , target , newIdx,cur);
    }
};
