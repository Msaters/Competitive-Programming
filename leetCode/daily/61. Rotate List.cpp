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
        if(head == nullptr) return head;

        int n = 0;
        ListNode* prev;
        ListNode* tail;
        for(auto tail = head; tail != nullptr; tail = tail->next) {
            n++;
            prev = tail;
        }
        k %= n;
        
        prev->next = head;

        ListNode* previous = prev;
        ListNode* shift = head;
        for(int i = 0; i < n - k; i++) {
            shift = shift->next;
            previous = previous->next;
        }

        previous->next = nullptr;
        return shift;
    }
};