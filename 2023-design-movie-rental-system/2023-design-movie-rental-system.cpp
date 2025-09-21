class MovieRentingSystem {
public:

    set<vector<int>> rented;
    unordered_map<int,set<vector<int>>> unRented;

    unordered_map<int,unordered_map<int,int>> price;
    

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto i: entries){
            int shop = i[0];
            int movie = i[1];
            int p = i[2];
            unRented[movie].insert({p,shop});
            price[movie][shop]=p;
        }
    }
    
    vector<int> search(int movie) {
        
        if(unRented.find(movie)==unRented.end()){
            return {};
        }

        vector<int> ans;
        
        for(auto i: unRented[movie]){
            int shop = i[1];
            ans.push_back(shop);
            if(ans.size()==5){
                break;
            }
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        int p = price[movie][shop];
        unRented[movie].erase(unRented[movie].find({p,shop}));

        rented.insert({p,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int p = price[movie][shop];
        rented.erase({p,shop,movie});
        unRented[movie].insert({p,shop});
    }
    
    vector<vector<int>> report() {

        vector<vector<int>> ans;
        for(auto i: rented){
            int shop = i[1];
            int movie = i[2];
            ans.push_back({shop,movie});

            if(ans.size()==5){
                break;
            }
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */