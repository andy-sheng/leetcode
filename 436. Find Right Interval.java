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
    private int binarySearch(int[][] arr, int key) {
        int start = 0;
        int end   = arr.length - 1;
        int mid = 0;
        while (start <= end && start > -1 && end < arr.length) {
            mid = (start + end) / 2;
            if (arr[mid][0] > key) {
                end = mid - 1;
            } else if (arr[mid][0] < key) {
                start = mid + 1;
            } else {
                return arr[mid][1];
            }
        }
        if (mid + 1 >= arr.length) return -1;
        else return arr[mid+1][1];
    }
    
    public int[] findRightInterval(Interval[] intervals) {
        int[] result = new int[intervals.length];
        int[][] tmp = new int[intervals.length][2];
        for (int i = intervals.length - 1; i > -1; i--) {
            tmp[i][0] = intervals[i].start;
            tmp[i][1] = i;
        }
        Arrays.sort(tmp, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] > o2[0]) {
                    return 1;
                } else {
                    return -1;
                }
            }
        });
        for (int i = intervals.length - 1; i > -1; i--) {
            result[i] = this.binarySearch(tmp, intervals[i].end);
        }
        return result;
    }
}