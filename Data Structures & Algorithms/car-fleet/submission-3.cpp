/**
target = 10 

pos              - 0   1   4  7
distanceToTarget - 10  9   6  3
spd              - 1   2   2  1
timeToTarget     - 10  4.5 3  3

**Car Fleet — Monotonic Queue Pattern (but no actual queue)**

Tag: Monotonic Queue (conceptually similar, but implemented with a variable instead of a queue). Sort cars by position, calculate time to destination, then scan from the end (closest to target). Keep the slowest fleet time ahead; whenever a bigger time appears before a smaller/equal time, it forms a new fleet.

Example:

```
target = 10

position:  0   1   4   7
speed:     1   2   2   1
time:     10  4.5  3   3

Scan from right:
3  -> fleet 1 (time = 3)
3  -> joins existing fleet (same time)
4.5 -> new fleet (slower, catches up later)
10 -> new fleet

Answer = 3 fleets
```

Pattern: Sort → compute "time to finish" → traverse backwards → count when current time > previous fleet time.


**/

typedef pair<int,int> pii;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pii> cars; 

        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](const pii& a, const pii& b) {
            return a < b;
        });

        int fleets = 0;
        double lastFleetTime = 0;

        for(int i = cars.size() - 1; i >= 0; i--) {
            int currPos = cars[i].first; 
            int currSpeed = cars[i].second;
            int distanceToTarget = target - currPos;
            double timeToTarget = distanceToTarget*1.0 / currSpeed; 

            if(timeToTarget > lastFleetTime) {
                fleets++;
                lastFleetTime = timeToTarget;
            }
        }

        return fleets;
    }
};
