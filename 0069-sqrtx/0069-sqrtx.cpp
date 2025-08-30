class Solution {
public:
    long long int sqrt(int n)
    {
        int start = 0;
        int end = n;
        int answer = -1;

        long long int mid = start + (end - start)/2;

        while(start <= end)
        {
            long long int square = mid*mid;

            if(square == n)
            {
                return mid;
            }
            else if(square < n)
            {
                answer = mid;
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
    int mySqrt(int x) {
        return sqrt(x);   
    }
};