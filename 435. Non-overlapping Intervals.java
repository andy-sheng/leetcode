/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public int eraseOverlapIntervals(Interval[] intervals) {
        if (intervals.length < 2) return 0;
        Arrays.sort(intervals, (Interval interval1, Interval interval2) -> {
            if (interval1.start > interval2.start || (interval1.start == interval2.end && interval1.end < interval2.end)) {
                return 1;
            }
            return -1;
        });
        int result = 0;
        int lastEnd = intervals[0].end;
        for (int i = 1; i < intervals.length; ++i) {
            if (lastEnd > intervals[i].start) {
                result++;
                if (intervals[i].end < lastEnd) { // remove the larger end one
                    lastEnd = intervals[i].end;
                }
            } else {
                lastEnd = intervals[i].end;
            }
        }
        return result;
    }
}
