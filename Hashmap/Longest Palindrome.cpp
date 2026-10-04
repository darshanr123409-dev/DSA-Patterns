#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {

        int res = 0;
        unordered_map<char, int> hashmap;

        // Count frequency
        for (auto ch : s) {
            hashmap[ch]++;
        }

        bool odd = false;

        // Use all even counts
        for (auto ch : hashmap) {
            int val = ch.second;

            if (val % 2 == 0) {
                res += val;
            }
            else {
                res += val - 1;
                odd = true;
            }
        }

        // One odd character can be placed in the center
        if (odd) {
            res++;
        }

        return res;
    }
};