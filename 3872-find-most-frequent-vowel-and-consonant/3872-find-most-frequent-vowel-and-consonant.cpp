class Solution {
public:
bool isVowel(char c)
{
    tolower(c);
    return{c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'};
}
    int maxFreqSum(string s) {
        vector<int> count(26,0);
        for(char c : s)
        {
            count[c - 'a']++;
        }

        int maxi1 = 0;
        int maxi2 = 0;
        
        for(int i=0; i<26; i++)
        {
            if(isVowel('a' + i))
            {
                maxi1 = max(maxi1, count[i]);
            }
            else
            {
                maxi2 = max(maxi2, count[i]);
            }
        }

        return maxi1 + maxi2;
    }
};