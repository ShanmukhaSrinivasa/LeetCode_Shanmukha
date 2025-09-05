class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(long long k=1; k<=60; k++)
        {
            long long target = num1 - k*num2;
            if(target >= 0 && __builtin_popcountll(target) <= k && k <= target)
            {
                return k;
            }
        }
        return -1;
    }
};