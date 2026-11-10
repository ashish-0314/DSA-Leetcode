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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr ;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL) return NULL;
        head = reverse(head);
        int maxi = head->val;
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL){
            if(curr->next->val < maxi){
                curr->next = curr->next->next;
            } else{
                maxi = curr->next->val ;
                curr = curr->next;
            }
        }
        return reverse(head);
    }
};