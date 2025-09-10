class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int users = languages.size();

        vector<set<int>> knows(users+1);
        for(int i=0; i<users; i++)
        {
            for(int lang : languages[i])
            {
                knows[i+1].insert(lang);
            }
        }

        set<int> needToTeach;
        for(auto &f : friendships)
        {
            int u = f[0], v = f[1];
            bool share = false;
            for(int lang : knows[u])
            {
                if(knows[v].find(lang) != knows[v].end())
                {
                    share = true;
                    break;
                }
            }

            if(!share)
            {
                needToTeach.insert(u);
                needToTeach.insert(v);
            }
        }

        if(needToTeach.empty())
        {
            return 0;
        }

        int ans = users;
        for(int l=1; l<=n; l++)
        {
            int count = 0;
            for(int u : needToTeach)
            {
                if(knows[u].find(l) == knows[u].end())
                {
                    count++;
                }
            }
            ans = min(ans,count);
        }
        return ans;
    }
};