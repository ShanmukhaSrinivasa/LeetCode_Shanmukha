class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;

        for(auto numbers : nums)
        {
            rightSum += numbers;
        }

        for(int i=0; i<nums.size(); i++)
        {
            rightSum -= nums[i];
            if(rightSum == leftSum)
            {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};