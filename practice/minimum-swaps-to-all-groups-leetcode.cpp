class Solution {
public:
    int minSwaps(vector<int>& nums) {
       int n= nums.size();
       int totalones=0;
       for(int i=0;i<n;i++){
        if(nums[i]==1) totalones++;
       } 
       if(totalones==0 || totalones==n){
        return 0;
       }
       int currones=0;
       for(int i=0;i<totalones;i++){
        if(nums[i]==1) currones++;
       }
       int maxones=0;
       for(int i=0;i<n;i++){
        currones-=nums[i];
        currones+=nums[(i+totalones)%n];
        maxones=max(maxones,currones);
       }
       return totalones-maxones;
    }
};