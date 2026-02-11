class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> zeroes;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zeroes.push_back({i,j});
                }
            }
        }
        int s=zeroes.size();
        for(int k=0;k<s;k++){
            int r =zeroes[k].first;
            int c =zeroes[k].second;
            for(int j=0;j<n;j++){
                matrix[r][j]=0;
            }
            for(int i=0;i<m;i++){
                matrix[i][c]=0;
            }  
        }
    }
};


//optimal approach

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0)
                firstRowZero = true;
        }

        
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0)
                firstColZero = true;
        }

       
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

       
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowZero) {
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }

       
        if (firstColZero) {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};