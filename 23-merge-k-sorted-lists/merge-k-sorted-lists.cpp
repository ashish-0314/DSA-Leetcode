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
    ListNode* merge(ListNode* list1 , ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode ;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                res->next = list1;
                list1 = list1->next;
            }
            else{
                res->next = list2;
                list2 = list2->next;
            }
            res= res->next;
        }
        if(list1) res->next = list1;
        else res->next = list2;
        return dummyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        while(n>1){
            for(int i = 0 ; i < n/2 ; i++){
                lists[i] = merge(lists[i],lists[n-i-1]);
            }
            n=(n+1)/2;
        }
        return lists[0];
    }
};