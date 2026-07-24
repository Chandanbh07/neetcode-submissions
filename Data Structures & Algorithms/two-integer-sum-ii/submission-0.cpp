class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        int n = numbers.size();
        
        for(int i=0;i<n;i++){
            int needed = target - numbers[i];

            if(mp.count(needed)) return {mp[needed],i+1};

            mp[numbers[i]] = i+1;
        }
    }
};
