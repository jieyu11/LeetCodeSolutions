/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        //intervals = vector<Interval>{};
        vector<Interval> result;
        if(intervals.empty()){
            result.push_back(newInterval);
            return result;
        }
        int n = intervals.size();
        if(newInterval.end < intervals[0].start){intervals.insert(intervals.begin(), newInterval); return intervals; }
        if(newInterval.start > intervals[n-1].end){intervals.push_back(newInterval); return intervals; }

        size_t i0 = -1, i1 = n;
        for(int i = 0; i<n; i++){
            if(intervals[i].end < newInterval.start){i0 = i;}
            if(intervals[i].start > newInterval.end){i1 = i; break;}
        }
        result.insert(result.end(), intervals.begin(), intervals.begin()+i0+1);
        newInterval.start = min(newInterval.start, intervals[i0+1].start);
        newInterval.end = max(newInterval.end, intervals[i1-1].end);
        result.push_back(newInterval);
        result.insert(result.end(), intervals.begin()+i1, intervals.end());

        return result;
    }
};
