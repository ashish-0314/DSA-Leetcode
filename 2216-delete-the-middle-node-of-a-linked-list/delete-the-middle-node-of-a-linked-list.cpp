/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;

        vector<ListNode*> nodes;

        ListNode* curr = head;

        while(curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int n = nodes.size();
        int mid = n / 2;

        nodes[mid - 1]->next = nodes[mid]->next;

        delete nodes[mid];

        return head;
    }
};