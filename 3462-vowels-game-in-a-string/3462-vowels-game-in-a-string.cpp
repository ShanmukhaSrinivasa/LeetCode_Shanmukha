class Solution {
public:
    bool isVowel(char c)
    {
        tolower(c);
        return {c=='a' || c=='e' || c=='i' || c=='o' || c=='u'};
    }
    
    bool doesAliceWin(string s) {
        int count = 0;
        for(char c : s)
            {
                if(isVowel(c))
                {
                    count++;
                }
            }
        return count>0;
    }
};