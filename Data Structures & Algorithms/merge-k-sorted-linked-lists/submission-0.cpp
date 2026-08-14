class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        // Put first node of every non-empty list into heap
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            ListNode* node = it.second;

            // Add smallest node to result
            tail->next = node;
            tail = tail->next;

            // Add next node from same list
            if (node->next != nullptr) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};