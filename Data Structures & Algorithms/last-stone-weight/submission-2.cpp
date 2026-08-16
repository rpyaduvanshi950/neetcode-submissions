class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int t1 = pq.top();
            pq.pop();

            int t2 = pq.top();
            pq.pop();

            if (t1 != t2) {
                pq.push(t1 - t2);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
