class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = 0;
        int leftSum = 0;

        for(auto number : nums)
        {
            rightSum += number;
        }

        for(size_t i =0; i<nums.size(); i++)
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