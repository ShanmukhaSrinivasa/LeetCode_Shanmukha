class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1= 0;
        int count2 = 0;
        int elem1 = INT_MIN;
        int elem2 = INT_MIN;

        for(int i=0; i<n; i++)
        {
            if(count1 == 0 && elem2 != nums[i])
            {
                count1 = 1;
                elem1 = nums[i];
            }
            else if(count2 ==0 && elem1 != nums[i])
            {
                count2 = 1;
                elem2 = nums[i];
            }
            else if(nums[i] == elem1)
            {
                count1++;
            }
            else if(nums[i] == elem2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> ls;
        count1 = 0;
        count2 = 0;
        for(int i=0; i<n; i++)
        {
            if(elem1 == nums[i])
            {
                count1++;
            }
            if(elem2 == nums[i])
            {
                count2++;
            }
        }
        int mini = (int)(n/3)+1;
        if(count1 >= mini)
        {
            ls.push_back(elem1);
        }
        if(count2 >= mini)
        {
            ls.push_back(elem2);
        }
        sort(ls.begin(), ls.end());
        return ls;
    }
};