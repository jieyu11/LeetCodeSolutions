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
        auto low = lower_bound(intervals.begin(), intervals.end(), newInterval,
                              [](const Interval* c, const Interval& newInterval) {return c->begin < newInterval.begin;});
        auto upp = upper_bound(intervals.begin(), intervals.end(), newInterval,
                              [](const Interval* c, const Interval& newInterval) {return c->end < newInterval.end;});
        size_t ilow = low - intervals.begin();
        size_t iupp = upp - intervals.begin();
        if(ilow==iupp) return intervals; // newInterval is in one of the intervals
        
    }
};
