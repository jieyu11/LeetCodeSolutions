class Solution {
public:
struct hightolow
{
    inline bool operator() (const pair<int, int> & p1, const pair<int, int> & p2)
    {
        if(p1.first  > p2.first) return true;
        if(p1.first == p2.first && p1.second < p2.second) return true;
        return false;
    }
};
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int n = people.size();
        if(n==0) return vector<pair<int, int>>{};
        
        sort(people.begin(), people.end(), hightolow());
        vector<pair<int, int>> result{ people[0] };
        for(int i=1; i<n; i++){
            vector<pair<int, int>>::iterator it = result.begin();
            for(int j=0; j<people[i].second; j++) it++;
            result.insert(it, people[i]);
        }
        return result;
    }
};
