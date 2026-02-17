class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        queue<int>temp;
        for(int i=0;i<n/2;i++){
            temp.push(q.front());
            q.pop();
        }
        int half=n/2;
        while(half--){
            q.push(temp.front());
            temp.pop();
            q.push(q.front());
            q.pop();
        }
    }
};