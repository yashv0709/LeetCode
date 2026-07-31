class Solution {
public:
  int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int result1 = 0;
        int result2 = 0;
        
        for (int i = start; i != destination; i = (i + 1) % distance.size()) {
            result1 += distance[i];
        }
        
        for (int i = destination; i != start; i = (i + 1) % distance.size()) {
            result2 += distance[i];
        }
        
        return min(result1, result2);
    }
};