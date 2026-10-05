#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
#define Node ListNode
#define data val
#define ed endl
#define null NULL

public:

    Node* reverse_node(Node* head, int times) {

        Node* cur = head;
        Node* pre = null;

        while (times--) {

            Node* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    ListNode* swapPairs(ListNode* head) {

        if (head == null) {
            return head;
        }

        Node* left = head;
        Node* res = null;
        Node* preleft = null;
        Node* right;

        int size = 2;

        while (true) {

            right = left;

            // Find second node
            for (int i = 0; i < size - 1; i++) {

                if (right == null) {
                    break;
                }

                right = right->next;
            }

            // We have a complete pair
            if (right) {

                Node* nextleft = right->next;

                reverse_node(left, size);

                // Connect previous pair
                if (preleft) {
                    preleft->next = right;
                }

                // First pair's new head
                if (res == null) {
                    res = right;
                }

                preleft = left;

                // Move to next pair
                left = nextleft;
            }

            // Only one node remaining
            else {

                if (preleft) {
                    preleft->next = left;
                }

                if (res == null) {
                    res = left;
                }

                break;
            }
        }

        return res;
    }
};