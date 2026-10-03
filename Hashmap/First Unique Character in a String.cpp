#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char,int> hash;
        for(auto ch : s){
            hash[ch]++;
        }
        for(int i=0 ;i<n ;i++){
            if(hash[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};