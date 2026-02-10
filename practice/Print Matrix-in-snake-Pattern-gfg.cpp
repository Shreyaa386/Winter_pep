class Solution {
  public:
    vector<int> snakePattern(vector<vector<int> > matrix) {
        // code here
        vector<int>ans;
        int n=matrix.size();
        int m= matrix[0].size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                for(int j=0;j<m;j++)
                ans.push_back(matrix[i][j]);
            }
            else{
                for(int j = m-1;j>=0;j--)
                ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};