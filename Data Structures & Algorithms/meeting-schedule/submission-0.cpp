/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }

0 30 -> true
5 10 -> false 
15 20


----

5 8 -> true 
9 15 -> true

end1 > start2 ==> false --> terminate 
end1 <= start2 ==> true

 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            if(a.start == b.start) {
                return a.end < b.end;
            }

            return a.start < b.start;
        });

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i-1].end > intervals[i].start) {
                return false; 
            }
        }

        return true;
    }
};
