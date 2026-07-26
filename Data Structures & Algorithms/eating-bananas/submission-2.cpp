class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = -1;

        sort(piles.begin(),piles.end());

        int st = 1, end = piles[n-1];
        while(st<=end){
            int k = st + (end-st)/2;
            if(isvalid(piles,h,k)){
                ans = k;
                end = k-1;
            }else{
                st = k+1;
            }
        }

        return ans;
    }

    bool isvalid(vector<int>& piles, int h, int k){
        int time_need = 0;
        int n = piles.size();

        for(int i = 0 ; i < n ; i++){
            time_need += (piles[i] + k - 1) / k;
        }

        return time_need <= h;
    }
};
