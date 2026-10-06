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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == null or head->next == null or k==0 ){
            return head;
        }
        Node* last = head;
        int n=1;
        while(last->next != null){
            n++;
            last = last->next;
        }
        
        k= k%n;
        if( k == 0){
            return head;
        }
        int cnt =1;
        Node* t = head;
        while(t!=null){
            if(cnt == (n-k)){
                break;
            }
            cnt++;
            t=t->next;
        }
        last->next = head;
        Node* res = t->next;
        t->next = null;
        return res;
    }
};