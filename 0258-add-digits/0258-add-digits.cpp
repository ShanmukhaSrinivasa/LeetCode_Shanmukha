class Solution {
public:
    int addDigits(int num) {
       int sum = 0;

       while(num > 0) 
       {
        int lastDigit = num%10;
        sum += lastDigit;
        num/=10;
       }

       while(sum > 9)
       {
        int temp = 0;
        while(sum>0)
        {
            temp += sum%10;
            sum/=10;
        }
        sum = temp;
       }
        return sum;
    }
};