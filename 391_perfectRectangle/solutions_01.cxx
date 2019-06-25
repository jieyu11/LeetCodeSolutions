class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {   
        long total_space = 0;
        // add the points, if a point is found two times, then remove it. 
        //Finally, it should be only four corner points left if it is a perfect rectangle
        set<pair<int,int>> points; 
        for(auto & r : rectangles){
            // x1, y1, x2, y2
            total_space += long(r[2] - r[0]) * (r[3] - r[1]);
            if(points.find({r[0],r[1]}) != points.end()) points.erase({r[0],r[1]}); else points.insert({r[0],r[1]});
            if(points.find({r[0],r[3]}) != points.end()) points.erase({r[0],r[3]}); else points.insert({r[0],r[3]});
            if(points.find({r[2],r[1]}) != points.end()) points.erase({r[2],r[1]}); else points.insert({r[2],r[1]});
            if(points.find({r[2],r[3]}) != points.end()) points.erase({r[2],r[3]}); else points.insert({r[2],r[3]});
       }
        if(points.size() != 4) return false;
        // the four points should form a rectangle!!!
        vector<pair<int,int>> vp(points.begin(), points.end());
        if(vp[0].first != vp[1].first) return false;
        if(vp[2].first != vp[3].first) return false;
        if(vp[0].second != vp[2].second) return false;
        if(vp[1].second != vp[3].second) return false;
        long total_space2 = (long(vp[2].first) - vp[0].first) * (long(vp[1].second) - vp[0].second);
        return total_space2 == total_space;
   }
};
