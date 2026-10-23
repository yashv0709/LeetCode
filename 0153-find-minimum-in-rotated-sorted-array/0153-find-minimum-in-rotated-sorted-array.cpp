class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int res=-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else{
                res=nums[mid];
                high=mid;
            }
        }
        return nums[low];
    }
};
