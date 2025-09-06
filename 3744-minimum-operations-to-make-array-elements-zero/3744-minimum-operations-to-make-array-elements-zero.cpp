class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        for(auto q : queries)
        {
            long long l = q[0];
            long long r = q[1];
            long long sum = 0;
            long long operation = 0;

            for(long long range=1; range <= r; range *= 4)
            {
                long long sr = max(range, l);
                long er = min(r, range*4-1);

                sum += max(0LL, ++operation * (er - sr + 1));
            }
            result += (sum + 1)/2;
        }
        return result;
    }
};