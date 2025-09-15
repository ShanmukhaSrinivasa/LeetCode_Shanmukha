class Solution {
public:
bool check(string &s ,unordered_map<char, int> &mp)
{
    for(char c: s){
        if(mp.find(c)!=mp.end()){
            return false;
        }
    }

    return true;
}
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char, int> mp;

        for (char c : brokenLetters) {
            mp[c]++;
        }

        string a = "";

        int count = 0;

        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                if (check(a, mp)) {
                    count++;
                }
                a = "";
            } else {
                a += text[i];
            }
        }
        if (check(a, mp)) {
            count++;
        }

        return count;  
    }
};