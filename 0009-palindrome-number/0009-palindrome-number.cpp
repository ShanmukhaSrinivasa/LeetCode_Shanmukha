class Solution {
public:
    bool isPalindrome(int x) {
        long long original_num = x;
        long long reverse_num =0;

        for(int i=1; x>0; i++)
        {
            int lastdigit = x%10;
            reverse_num = reverse_num * 10 + lastdigit;
            x/=10;
        }

        if(original_num == reverse_num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};