class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = 0;
        int rmax = 0;

        int st=0,end=n-1;
        int ans = 0;
        while(st<end){
            lmax = max(lmax,height[st]);
            rmax = max(rmax,height[end]);

            if(lmax < rmax){
              ans += lmax - height[st];
              st++;
            }else{
                ans+= rmax - height[end];
                end--;
            }
        }
        return ans;
    }
};
