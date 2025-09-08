class Solution {
private:
    bool possibleBouquets(vector<int>&bloomDay, int day, int m, int k)
    {
        int count = 0;
        int noOfBouquets = 0;
        int n = bloomDay.size();

        for(int i=0; i<n; i++)
        {
            if(bloomDay[i]<=day)
            {
                count++;
            }
            else
            {
                noOfBouquets += (count/k);
                count = 0;
            }
        }
        noOfBouquets += (count/k);
        return noOfBouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m * 1LL * k * 1LL;
        if(val > n)
        {
            return -1;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0; i<n; i++)
        {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;

        while(low <= high)
        {
            int mid = (low+high)/2;
            if(possibleBouquets(bloomDay, mid, m, k))
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