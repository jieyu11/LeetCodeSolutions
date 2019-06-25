/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        //points=vector<Point>{Point(1,1),Point(1,1),Point(1,1)};
        int n = points.size();
        if(n<=2) return n;
        // remove duplicate points and give this point a count
        vector<int> dupCounts(n,1);
        for(int i=0; i<n-1; i++){
            if(dupCounts[i] <= 0) continue;
            for(int j=i+1; j<n; j++){
                if( points[i].x == points[j].x && points[i].y == points[j].y ){ 
                    dupCounts[i]++; 
                    dupCounts[j] = 0;
                }
            }
        }
        
        int nmax =0;
        for(int i=0; i<n-1; i++){
            if(dupCounts[i] <= 0) continue;
            map<pair<int, int>, int> slopeCounts;
            for(int j=i+1; j<n; j++){
                if(dupCounts[j] <= 0) continue;
                
                pair<int,int> dxdy = make_pair(points[j].x - points[i].x, points[j].y - points[i].y);
                // look for the existing slopes, check if this one is already included
                bool found = false;
                int count = 0;
                for(auto & a : slopeCounts){
                    if( long( dxdy.first ) * (a.first).second == long( (a.first).first ) * dxdy.second ){
                        a.second += dupCounts[j];
                        found = true;
                        count = a.second;
                        break;
                    }
                }
                if(!found){
                    slopeCounts[dxdy] = dupCounts[j];
                    count = dupCounts[j];
                }
                //cout<<"p1: "<<points[i].x<<", "<< points[i].y<<"; p2: "<< points[j].x <<", "<< points[j].y 
                //    <<" found ? "<<found<<" cout "<<count<<endl;
            }
            if(dupCounts[i] > nmax) nmax = dupCounts[i]; // if there is only one point
            for(auto & a : slopeCounts) if( a.second + dupCounts[i] > nmax) nmax = a.second + dupCounts[i];
        }

        return nmax;
    }
};
