class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N_total = (long long)n * n;

        long long sum = ((long long)N_total * (N_total+1))/2;
        long long sqSum = ((long long)N_total * (N_total+1) * (2*N_total+1))/6;

        long long actualSum = 0;
        long long actualsqSum = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                actualSum += grid[i][j];
                actualsqSum += grid[i][j] * grid[i][j];

            }
        }

        long long val1 = actualSum - sum;
        long long val2 = actualsqSum - sqSum;
        val2 = val2/val1;

        long long x = (val1 + val2)/2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};