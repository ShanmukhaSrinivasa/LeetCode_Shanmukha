class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low < high)
        {
            int mid = (low+high)/2;

            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low = low + 1;
                high = high - 1;
                continue;
            }
            //left sorted
            if(nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return nums[low];
    }
};