#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while( fast != nullptr && fast->next != nullptr ){
            slow = slow->next; // 1
            fast = fast->next->next; // 2
            if(slow == fast) 
            {
                slow = head ;
                while( slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                    return slow;
            }
        }
        return nullptr;
}
};
ListNode *detectCycle(ListNode *head) {
        
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    unordered_map<ListNode*, int> map;
    ListNode* temp = head;
    while(temp != nullptr) {
        // If node already exists, cycle is present
        if(map.find(temp) != map.end()) {
            return temp;
        }
        map[temp] = 1;
        temp = temp->next;
    }
    return nullptr;
}