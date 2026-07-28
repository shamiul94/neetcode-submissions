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

5    9  15
         i

10  20  40
          j

currRoom = 0
req = 2

 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts; 
        vector<int> ends; 

        for(const Interval& interval: intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        sort(starts.begin(), starts.end()); 
        sort(ends.begin(), ends.end()); 

        int i = 0; 
        int j = 0;
        
        int currRoomInUse = 0; 
        int totalRequiredRoom = 0; 

        while(i < starts.size() && j < ends.size()) {
            if(starts[i] < ends[j]) {
                currRoomInUse++;
                totalRequiredRoom = max(totalRequiredRoom, currRoomInUse);
                i++; 
            } else {
                currRoomInUse--; 
                j++; 
            }
        }

        return totalRequiredRoom;
    }
};
