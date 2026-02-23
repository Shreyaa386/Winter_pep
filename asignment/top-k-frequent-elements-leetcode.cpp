class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;    
        }
        priority_queue<pair<int,int>> pq;
        for(auto it = freq.begin(); it != freq.end(); it++) {
        pq.push({it->second, it->first});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++) {
        ans.push_back(pq.top().second);
        pq.pop();
        }
        return ans;
    

        
    }
};