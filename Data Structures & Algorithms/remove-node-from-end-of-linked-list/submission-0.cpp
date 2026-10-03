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
    ListNode* reverse(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* temp = head;
        ListNode* back = nullptr;

        while(temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = back;
            back = temp;
            temp = front;
        }

        return back;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);

        if(n == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            ListNode* temp = head;

            for(int i = 1; i < n - 1; i++) {
                temp = temp->next;
            }

            ListNode* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }

        head = reverse(head);

        return head;
    }
};
