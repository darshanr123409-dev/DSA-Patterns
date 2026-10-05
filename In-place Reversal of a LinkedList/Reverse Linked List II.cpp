#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || left==right ){
            return head;
        }
        ListNode* last = head;
        ListNode* before = nullptr;
        int pos =1 ;
        
            while(pos < left){
                before = last;
                last=  last->next;
                pos++;
            }
        
        ListNode* current = last;
        ListNode* prev = nullptr;
        int times = right - left + 1;
        while(times--){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        last->next = current;
        if(before){
            before->next = prev;
            return head;
        }
        else {
            return prev;
        }
        
    }
};