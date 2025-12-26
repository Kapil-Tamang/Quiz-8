class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Max-heap: the biggest stone is always on top
        priority_queue<int> pq;

        // Put all stones into the heap
        for (int w : stones) {
            pq.push(w);
        }

        // Keep smashing while we have at least 2 stones
        while (pq.size() >= 2) {
            int y = pq.top();  // heaviest
            pq.pop();
            int x = pq.top();  // second heaviest
            pq.pop();

            // If they are not equal, push the difference back
            if (y != x) {
                pq.push(y - x);
            }
            // If y == x, both are destroyed, push nothing
        }

        // If one stone left, return it; otherwise return 0
        if (pq.empty()) return 0;
        return pq.top();
    }
};
