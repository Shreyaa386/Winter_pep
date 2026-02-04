class Solution {
public:

    int check(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int n=nums.size();
        int left=0, right=0, sum=0, count=0;
        for(right=0;right<n;right++){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=(right-left+1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
       int ans = check(nums,goal) - check(nums,goal-1);
       return ans;
    }
}; 