int firstOccurence(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;

    int mid = start + (end - start)/2;

    int answer = -1;

    while(start <= end)
    {
        if(nums[mid] == target)
        {
            answer = mid;
            end = mid - 1;
        }
        else if(target > nums[mid])    
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return answer;
}

int lastOccurence(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;

    int mid = start + (end - start)/2;

    int answer = -1;

    while(start <= end)
    {
        if(nums[mid] == target)
        {
            answer = mid;
            start = mid + 1;
        }
        else if(target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return answer;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> results(2,-1);
        results[0] = firstOccurence(nums, target);
        results[1] = lastOccurence(nums, target);

        return results;
    }
};