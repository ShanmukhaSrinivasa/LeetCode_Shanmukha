class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       long long sum = 0;
       long long maxi = LONG_MIN;
       long long ansStart = -1;
       long long ansEnd = -1;
       long long start = 0;

       for(int i=0; i<nums.size(); i++)
       {
        if(sum == 0)
        {
            start = i;
        }
        sum += nums[i];

        if(sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0)
        {
            sum = 0;
        }

       }
       return maxi;
    }
};