class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Xor = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            Xor = Xor ^ nums[i];
        }
        return Xor;
    }
};