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
private:
    ListNode* reversedList(ListNode* node, ListNode* &head) {
        if(node->next == nullptr) {
            head = new ListNode(node->val);
            return head;
        }
        return reversedList(node->next, head)->next = new ListNode(node->val);
    }
public:
    int pairSum(ListNode* head) {
        ListNode* reverseHead;
        reversedList(head, reverseHead);

        ListNode* itRev = reverseHead;
        ListNode* it = head;
        int maxTwinSum = 0;
        while(it != nullptr) {
            maxTwinSum = max(maxTwinSum, it->val + itRev->val);
            it = it->next;
            itRev = itRev->next;
        }

        return maxTwinSum;
    }
};