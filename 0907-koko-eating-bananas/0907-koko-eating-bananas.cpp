class Solution {
    private:
    int findMax(vector<int> &piles)
    {
        int n = piles.size();
        int maxElem = INT_MIN;

        for(int i=0; i<n; i++)
        {
            maxElem = max(maxElem, piles[i]);
        }
        return maxElem;
    }

    long long calcTotalHours(vector<int>&piles, int hourly)
    {
        int n = piles.size();
        long long totalH = 0;

        for(int i=0; i<n; i++)
        {
            totalH += ceil((double)piles[i]/(double)hourly);
        }
        return totalH;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while(low <= high)
        {
            int mid = (low+high)/2;
            long long totalH = calcTotalHours(piles,mid);
            if(totalH <= h)
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