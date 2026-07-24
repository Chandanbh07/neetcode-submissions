class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i=0,j=0;
        vector<int> temp;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                 temp.push_back(nums1[i]);
                 i++;
            }
            else{
                 temp.push_back(nums2[j]);
                 j++;
            }
        }
        while(i<n1){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j<n2){
            temp.push_back(nums2[j]);
            j++;
        }
         
        int med = (n1+n2)/2;
        if((n1+n2)%2 != 0) return temp[med];
        else return (double)(temp[med]+temp[med-1])/2;
    }
};
