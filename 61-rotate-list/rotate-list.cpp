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
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        int len = 1 ;
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }
        k%=len;
        if(k==0) return head;
        temp->next=head;
        int cnt = len-k-1;
        ListNode* temp2 = head;
        while(cnt>0){
            cnt--;
            temp2 = temp2->next;
        }
        head = temp2->next;
        temp2->next = NULL;
        return head;
    }
};