class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xor1 = 0;
        int Xor2 = 0;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            Xor2 = Xor2 ^ nums[i];
            Xor1 = Xor1 ^ (i+1);
        }

        // Xor1 = Xor1 ^ n;
        return Xor1 ^ Xor2;
    }
};