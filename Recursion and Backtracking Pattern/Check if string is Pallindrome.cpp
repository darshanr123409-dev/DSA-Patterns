#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check_is_poli(string& s,int low ,int high){
        int length = high -low +1;
        
        if(length == 0 or length == 1){
            return true;
        }
        if(s[low]!=s[high]){
            return false;
            
        }
        return check_is_poli(s,low+1,high-1); 
    }
    bool isPalindrome(string& s) {
        // code here
        int n = s.size();
        int high = n-1;
        int low = 0;
        int length = high -low +1;
        if(length == 0 or length == 1)
            return true;
        
        return check_is_poli(s,low,high);
        }
        
};