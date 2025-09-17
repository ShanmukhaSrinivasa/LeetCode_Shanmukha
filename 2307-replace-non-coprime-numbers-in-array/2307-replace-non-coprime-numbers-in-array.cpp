class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long int> s;
        int n = nums.size();
        vector<int> ans;
        s.push(nums[0]);

        for (int i = 1; i < n; i++) {

            long long int num = nums[i];
            while (!s.empty() &&( __gcd(s.top(),num)>1)) {
                num=(num*s.top())/__gcd(s.top(),num);
               s.pop();
               
            } 
            s.push(num);
            
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    
    }
};