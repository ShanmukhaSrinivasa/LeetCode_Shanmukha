class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;
        while(n!=0)
    {
        int digit = n%10;
        product *= digit;
        sum += digit;
        n/=10;
    }
        int result = product - sum;
        return result;
    }
        
};