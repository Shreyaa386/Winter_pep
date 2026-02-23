class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int count = 0;
        int currMax = 0;

        for (int num : nums) {
            if (num >= currMax) {
                count++;
                currMax = num;
            } else {
                currMax = max(currMax, num);
            }
        }

        return count;
    }
};