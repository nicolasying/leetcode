#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res1 = l1;
        while(l1->next != nullptr && l2->next != nullptr) {
            l1->val += l2->val;
            if (l1->val >= 10) {
                l1->val -= 10;
                l1->next->val += 1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l2->next != nullptr) {
            l1->next = l2->next;
        }

        l1->val += l2->val;
        while(l1->val >= 10) {
            l1->val -= 10;
            if(l1->next!= nullptr){
                l1 = l1->next;
                l1->val += 1;
            } else {
                l1->next = new ListNode(1);
            }
        }
        return res1;
    }
};