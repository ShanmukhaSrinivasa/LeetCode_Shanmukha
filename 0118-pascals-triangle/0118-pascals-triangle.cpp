class Solution {
public:
    vector<int> generateRows (int rows)
    {
        int ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col=1; col < rows; col++)
        {
            ans = ans * (rows - col);
            ans = ans/(col);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ansTriangle;
        for(int i=1; i<=numRows; i++)
        {
            ansTriangle.push_back(generateRows(i));
        }
        return ansTriangle;
    }
};