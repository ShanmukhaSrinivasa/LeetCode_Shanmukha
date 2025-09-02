class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool col0 = true;

        // Mark zeros
        for(int i=0; i<n; i++) {
            if(matrix[i][0] == 0) col0 = false;
            for(int j=1; j<m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero cells based on markers
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero first row if needed
        if(matrix[0][0] == 0) {
            for(int j=0; j<m; j++)
                matrix[0][j] = 0;
        }

        // Zero first column if needed
        if(!col0) {
            for(int i=0; i<n; i++)
                matrix[i][0] = 0;
        }
    }
};
