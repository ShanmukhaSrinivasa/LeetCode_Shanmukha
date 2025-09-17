class FoodRatings {
public:
    map<string,string> foodToCuisine;
    map<string,set<pair<int,string>>> Cuisine;
    map<string,int> rating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodToCuisine[foods[i]]=cuisines[i];
            Cuisine[cuisines[i]].insert({-ratings[i],foods[i]});
            rating[foods[i]]=ratings[i];
        } 
    }
    
    void changeRating(string food, int newRating) {
        string cuisineName = foodToCuisine[food];
        Cuisine[cuisineName].erase({-rating[food],food});
        rating[food]=newRating;
        Cuisine[cuisineName].insert({-rating[food],food});
    }
    
    string highestRated(string cuisine) {
        return Cuisine[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */