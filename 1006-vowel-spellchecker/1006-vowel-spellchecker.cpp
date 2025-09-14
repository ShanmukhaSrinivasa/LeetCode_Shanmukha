class Solution {
public:
string makeLower(string s)
{
    string ans = "";
    for(char c : s)
    {
        ans += tolower(c);
    }
    return ans;
}

bool isVowel(char c)
{
    tolower(c);
    return {c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'};
}
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

        unordered_map<string,int> mp;
        unordered_map<string , string> insensitive;
        unordered_map<string , string> vowels;

    for(auto i : wordlist)
    {
        mp[i]++;
        string s = makeLower(i);
        if(insensitive.find(s) == insensitive.end())
        {
            insensitive[s] = i;
        }

        string withoutVowels = "";
        for(char c : s)
        {
            if(!isVowel(c))
            {
                withoutVowels += c;
            }
            else
            {
                withoutVowels += '#';
            }
        }
        if(vowels.find(withoutVowels) == vowels.end())
        {
            vowels[withoutVowels] = i;
        }
    }

    vector<string> ans;
    for(auto s : queries)
    {
        if(mp.find(s) != mp.end())
        {
            ans.push_back(s);
        }
        else if(insensitive.find(makeLower(s)) != insensitive.end())
        {
            ans.push_back(insensitive[makeLower(s)]);
        }
        else
        {
            string withoutVowels = "";
            string sLower = makeLower(s);
            for(char c : sLower)
            {
                if(!isVowel(c))
                {
                    withoutVowels += c;
                }
                else
                {
                    withoutVowels += '#';
                }
            }
            if(vowels.find(withoutVowels) != vowels.end())
            {
                ans.push_back(vowels[withoutVowels]);
            }
            else
            {
                ans.push_back("");
            }
        }
    }
    return ans;
    }
};