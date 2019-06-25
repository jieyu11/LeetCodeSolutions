class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        if(n<=1) return n;
        int idx = 0;
        int narrow = 0;
        while( idx < n ){
           // find where the minimum up value is lower than the down value, so that
           // such two numbers would create a gap like [1, 5], [6,9]
           // only when this happens, one should fire an arrow to shoot the lower end balloons.
            int xup_min = points[idx].second;
            int j = idx+1;
            for(; j < n; j++){
                if(xup_min < points[j].first){
                    break;
                }else if(xup_min > points[j].second){ xup_min = points[j].second;}
            }
            narrow++;
            idx = j;
        }
        return narrow;
    }
};
