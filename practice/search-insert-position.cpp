class Solution {
public:
    int solve(vector<int> &nums,int target,int low ,int high){
        if(low>high)
        return low;
        int mid= low +(high-low)/2;
        if(nums[mid]==target)
        return mid;
        else if(nums[mid]>target)
        return solve(nums,target,low,mid-1);
        else
        return solve(nums, target, mid+1, high);
    }
    int searchInsert(vector<int>& nums, int target) {
       int n = nums.size();
       return solve(nums,target,0,n-1);
    }
};