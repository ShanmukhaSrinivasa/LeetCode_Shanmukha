class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int elem;

        for(int i=0; i<nums.size(); i++)
        {
            if(count == 0)
            {
                count = 1;
                elem = nums[i];
            }
            else if(nums[i] == elem)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        int count1 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == elem)
            {
                count1++;
            }
            if(count1 > (nums.size()/2))
            {
                return nums[i];
            }
        }
        return -1;
    }
};