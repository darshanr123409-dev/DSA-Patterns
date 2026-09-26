#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while (temp != nullptr) {

            ListNode* front = temp->next;

            temp->next = prev;

            prev = temp;

            temp = front;
        }

        return prev;
    }
};