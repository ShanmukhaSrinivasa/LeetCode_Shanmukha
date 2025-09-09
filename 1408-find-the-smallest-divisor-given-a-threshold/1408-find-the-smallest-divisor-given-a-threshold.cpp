class Solution {
private:
    int sumOfDivisions(vector<int>&nums, int divisor)
    {
        int n = nums.size();
        int sum = 0;

        for(int i=0; i<n; i++)
        {
            int division = ceil((double)nums[i]/(double)divisor);
            sum += division;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, nums[i]);
        }

        int low = 1;
        int high = maxi;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(sumOfDivisions(nums, mid) <= threshold)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};