class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans (n,0);
        int sum = 0;

        for(int i=0; i<n-1; i++)
        {
            ans[i] = i + 1;
            sum += ans[i];
        }

        ans[n-1] = -sum;
        return ans;
    }
};