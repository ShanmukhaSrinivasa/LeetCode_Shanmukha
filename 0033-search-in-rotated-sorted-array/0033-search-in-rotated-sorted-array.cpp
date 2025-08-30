int findPivot(vector<int>&nums)
{
    int start = 0;
    int end = nums.size() - 1;

    int mid = start + (end - start)/2;

    while(start < end)
    {
        if(nums[mid] >= nums[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int binarySearch(vector<int> &nums, int s, int e, int key)
{
    int start = s;
    int end = e;

    int mid = start + (end - start)/2;

    while(start <= end)
    {
        if(nums[mid] == key)
        {
            return mid;
        }
        else if(key > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        if(target >= nums[pivot] && target <= nums[nums.size()-1])
        {
            return binarySearch(nums, pivot, nums.size()-1, target);
        }
        else
        {
            return binarySearch(nums, 0, pivot-1, target);
        }
    }
};