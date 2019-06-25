class Solution {
public:
    // given a sorted vector
    // return the maximum length of a serial of continuous numbers
    // e.g. 1,3,4,7,9 should return 2
    int getMaxContinuous_Vector(vector<int> & idvec){        
        int lmax = 1, len = 1;
        for(int il=1; il<idvec.size(); il++){
            if(idvec[il] - idvec[il-1] == 1) len++;
            else{
                if(lmax < len) lmax = len;
                len = 1;
            }
        }
        if(lmax < len) lmax = len;
        return lmax;
    }

    int getMaxContinuous(set<int> & idset){        
        int lmax = 1, len = 1;
        set<int>::iterator it0 = idset.begin();
        
        while( true ){
            int x0 = *it0;
            it0++;
            if( it0 == idset.end()) break;
            int x1 = *it0;
            
            if(x1 - x0 == 1) len++;
            else{
                if(lmax < len) lmax = len;
                len = 1;
            }
        }
        if(lmax < len) lmax = len;
        return lmax;
    }
    int largestRectangleArea(vector<int>& heights) {
        /*
        input: 0 -- 19999, time limit
        
        heights = vector<int>(200);
        iota (std::begin(heights), std::end(heights), 0);
        */

        
        int hmax = 0;
        int nh = heights.size();
        if( nh == 0 ) return hmax;
        if( nh == 1 ) return heights[0];
        
        // desending map
        map<int, vector<int>, std::greater<int>> hmap;
        for(int i=0; i<nh; i++){
            if(hmap.find(heights[i]) == hmap.end())
                hmap.insert( make_pair( heights[i], vector<int>{i}) );
            else
                hmap[ heights[i] ].push_back( i );
        }
        
        // keep the indexes into a vector
        // starting to include index from the largest heights
        // 
        // get the longest length for each height (including all height greater than itself)
        // square = (longest length) * height
        /*
        vector<int> idvec; 
        idvec.reserve(nh);
        */
        set<int> idset;
        for(map<int, vector<int>>::iterator it = hmap.begin(); it!= hmap.end(); it++){
            // idvec.insert( idvec.end(), (it -> second).begin(), (it -> second).end() );
            // sort(idvec.begin(), idvec.end());
            // int len = getMaxContinuous( idvec );
            idset.insert( (it -> second).begin(), (it -> second).end() );
            
            // if the current maximum square is larger than the maximum possible square 
            // from this test, then continue.
            if(idset.size() * (it -> first) <= hmax ) continue;
            
            int len = getMaxContinuous( idset );
            int sqr = len * it -> first;
            if(sqr > hmax) hmax = sqr;
        }
        return hmax;
    }
};
