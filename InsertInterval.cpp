class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        int n=intervals.size();
        if(n==0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        int l=searchLeft(intervals, newInterval);
        int r=searchRight(intervals, newInterval);
        
        if(l+1<=r-1){
            newInterval.start=min(newInterval.start, intervals[l+1].start);
            newInterval.end=max(newInterval.end, intervals[r-1].end);
            intervals.erase(intervals.begin()+l+1, intervals.begin()+r);
        }
        intervals.insert(intervals.begin()+l+1, newInterval);
        
        return intervals;
        
    }

private:
    // find index of the insert point of newInterval.start
    int searchLeft(vector<Interval> &intervals, Interval newInterval) {
        int n=intervals.size();
        if(intervals[n-1].end<newInterval.start) return n-1;
        
        int l=0; int r=n-1;
        while(l<r) {
            int m=l+(r-l)/2;
            if(intervals[m].end<newInterval.start) l=m+1;
            else r=m;
        }
        
        return l-1;
    }
    
    // find index of the insert point of newInterval.end
    int searchRight(vector<Interval> &intervals, Interval newInterval) {
        int n=intervals.size();
        if(intervals[n-1].start<=newInterval.end) return n;
        
        int l=0; int r=n-1;
        while(l<r) {
            int m=l+(r-l)/2;
            if(intervals[m].start<=newInterval.end) l=m+1;
            else r=m;
        }
        
        return l;
    }
    
};
