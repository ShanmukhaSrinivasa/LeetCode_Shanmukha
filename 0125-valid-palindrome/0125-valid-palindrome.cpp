class Solution {
public:
    bool isPalindrome(string s) {
      deque<char> d;

      for(auto c : s)
      {
        if(isalnum(c))
        {
            d.push_back(toupper(c));
        }
      }

      char c1;
      char c2;

      while(d.size() > 1)
      {
        c1 = d.front();
        c2 = d.back();

        d.pop_front();
        d.pop_back();

        if(c1 != c2)
        {
            return false;
        }
      }

      return true;
    }
};